
/**
 *	Include Header
 */
#include "Material.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;




/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include ConstantBuffer
 */
#include <ING/Rendering/API/Resource/ConstantBuffer/ConstantBuffer.h>



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



/**
 *	Include Drawable Category
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>



#include <vector>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IMaterial::IMaterial(const std::string& name, IShader* shader) : 
			shader(0),
			propertyBuffer(0),
			propertyPData(0),
			cbufferVector(GetMinimumCBufferCount())
		{

			this->name = name;

			SetShader(shader);

		}

		IMaterial::~IMaterial()
		{



		}



		/**
		 *	Release Methods
		 */
		void IMaterial::Release()
		{

			ReleasePropertyBuffer();

			cbufferVector.clear();

			delete this;

		}



		/**
		 *	Properties
		 */
		void			IMaterial::SetShader(IShader* shader) {
			
			if (shader == this->shader) return;

			if (this->shader != nullptr) {

				this->shader->RemoveMaterial(this);

			}

			ReleasePropertyBuffer();

			this->shader = shader;

			shader->AddMaterial(this);

			CreatePropertyBuffer();

			UpdateViewVector();

			UpdateCBufferVector();
		
		}

		unsigned int	IMaterial::GetPropertyIndex(const std::string& name) {

			if (shader == 0) return 0;

			return shader->GetPropertyIndex(name);

		}

		unsigned int	IMaterial::GetPropertyOffset(const std::string& name) {

			if (shader == 0) return 0;

			return shader->GetPropertyVector()[shader->GetPropertyIndex(name)].offset;

		}

		void			IMaterial::SetCBufferVector(const std::vector<IBuffer*>& cbufferVector) {

			memcpy(this->cbufferVector[0], cbufferVector[0], sizeof(IBuffer*) * cbufferVector.size() + 1);

			this->cbufferVector[cbufferVector.size() - 1] = propertyBuffer;

		}

		std::vector<MaterialView>	IMaterial::GetViewsByType(const std::string& type) {

			unsigned int viewCount = viewType2ViewIndexVectorMap[type].size();

			std::vector<MaterialView> result(viewCount);

			for (unsigned int i = 0; i < viewCount; ++i) {

				result[i] = viewVector[viewType2ViewIndexVectorMap[type][i]];

			}

			return result;

		}



		/**
		 *	Methods
		 */
		void IMaterial::Apply(const std::string& passName) {

			if (shader != 0) {

				GetShader()->Apply(passName);

				IDeviceContext* context = shader->GetDevice()->GetImmediateContext();

				if (shader->GetPropertyCount() > 0) {

					//context->PSSetConstantBuffers(cbufferVector);
					//context->VSSetConstantBuffers(cbufferVector);

				}

			}

		}


		void IMaterial::CreatePropertyBuffer() {

			if (shader == 0) return;

			if (shader->GetPropertyCount() == 0) return;

			unsigned int propertyTotalSize = shader->GetPropertyTotalSize();

			propertyPData = (char*)malloc(propertyTotalSize);

			propertyBuffer = IConstantBuffer::Create(shader->GetDevice(), propertyTotalSize, 0);

			cbufferVector[cbufferVector.size() - 1] = propertyBuffer;

		}
		void IMaterial::ReleasePropertyBuffer() {

			if (propertyBuffer != 0) {

				propertyBuffer->Release();

				propertyBuffer = 0;

				free(propertyPData);

				propertyPData = 0;

			}

		}
		void IMaterial::UpdatePropertyBuffer() { propertyBuffer->UpdateData(propertyPData); }

		void IMaterial::UpdateViewVector() {

			const std::vector<ShaderView>& shaderViewVector = shader->GetViewVector();

			unsigned int viewCount = shaderViewVector.size();

			std::vector<MaterialView> materialViewVector(viewCount);

			viewType2ViewIndexVectorMap.clear();

			for (unsigned int i = 0; i < viewCount; ++i) {

				IView* view = 0;

				if (viewName2ViewIndexMap.find(shaderViewVector[i].name) != viewName2ViewIndexMap.end()) {

					view = viewVector[
						viewName2ViewIndexMap[shaderViewVector[i].name]
					].view;

				}

				materialViewVector[i] = MaterialView(

					shaderViewVector[i].name,

					shaderViewVector[i].type,

					view,

					i

				);

				if (viewType2ViewIndexVectorMap.find(shaderViewVector[i].type) == viewType2ViewIndexVectorMap.end()) {

					viewType2ViewIndexVectorMap[shaderViewVector[i].type] = std::vector<unsigned int>(1);

				}
				else {

					viewType2ViewIndexVectorMap[shaderViewVector[i].type].resize(viewType2ViewIndexVectorMap[shaderViewVector[i].type].size() + 1);

				}

				viewType2ViewIndexVectorMap[shaderViewVector[i].type][viewType2ViewIndexVectorMap[shaderViewVector[i].type].size() - 1] = i;

				viewName2ViewIndexMap[shaderViewVector[i].name] = i;

			}

			viewVector = materialViewVector;

			for (auto it = viewName2ViewIndexMap.cbegin(); it != viewName2ViewIndexMap.cend();)
			{
				if (!shader->IsHaveView(it->first))
				{
					viewName2ViewIndexMap.erase(it++);
				}
				else
				{
					++it;
				}
			}

		}

		void	IMaterial::UpdateCBufferVector() {

			unsigned int cbufferCount = GetMinimumCBufferCount() + shader->GetCBufferCount();

			cbufferVector.resize(cbufferCount);

		}

		IBuffer* IMaterial::GetCBuffer(const std::string& name) {

			return cbufferVector[shader->GetCBufferIndex(name)];

		}

		void	IMaterial::SetCBuffer(const std::string& name, IBuffer* cbuffer) {

			cbufferVector[shader->GetCBufferIndex(name)] = cbuffer;

		}

		IView*	IMaterial::GetView(const std::string& name) {

			return viewVector[viewName2ViewIndexMap[name]].view;

		}

		void	IMaterial::SetView(const std::string& name, IView* view) {

			viewVector[viewName2ViewIndexMap[name]].view = view;

		}

		void IMaterial::Update() {



		}

	}

}
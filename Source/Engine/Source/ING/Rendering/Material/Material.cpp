
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
#include <ING/Rendering/Drawable/Category/Category.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>





namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IMaterial::IMaterial(const std::string& name, IShader* shader) : 
			shader(0),
			propertyBuffer(0),
			propertyPData(0),
			cbufferVector(1)
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



		/**
		 *	Methods
		 */
		void IMaterial::Apply(const std::string& passName) {

			if (shader != 0) {

				GetShader()->Apply(passName);

				IDeviceContext* context = shader->GetDevice()->GetContext();

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

		void IMaterial::Update() {



		}

	}

}
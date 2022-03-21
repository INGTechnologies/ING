
/**
 *	Include Header
 */
#include "DrawableMaterial.h"



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
		DrawableMaterial::DrawableMaterial(const std::string& name, IShader* shader) :
			IMaterial(name, shader)
		{



		}

		DrawableMaterial::~DrawableMaterial()
		{



		}



		/**
		 *	Methods
		 */
		void	DrawableMaterial::AddState(const std::string& name, IState* state) {

			stateName2StateMap[name] = state;

		}

		IState* DrawableMaterial::GetState(const std::string& name) {

			return stateName2StateMap[name];
			
		}

		void	DrawableMaterial::RemoveState(const std::string& name) {

			stateName2StateMap.erase(name);

		}

		void	DrawableMaterial::Destroy(const std::string& name) {

			delete GetState(name);

			RemoveState(name);

		}

		void DrawableMaterial::Apply(const std::string& passName) {

			IShader* shader = GetShader();

			if (shader != 0) {

				shader->Apply(passName);

				IDeviceContext* context = shader->GetDevice()->GetContext();

				for (auto item : stateName2StateMap) {

					//stateName2StateMap[item.first]->Apply();

				}

				if (shader->GetPropertyCount() > 0) {

					context->PSSetConstantBuffers(GetCBufferVector());
					context->VSSetConstantBuffers(GetCBufferVector());

				}

			}

		}

	}

}
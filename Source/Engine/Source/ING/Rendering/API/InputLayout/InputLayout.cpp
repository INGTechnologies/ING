
/**
 *	Include Header
 */
#include "InputLayout.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 InputLayout
 */
#include <ING/Rendering/API/DirectX11/InputLayout/InputLayout.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IInputLayout::IInputLayout(IDevice* device) {

			this->device = device;

		}

		IInputLayout::~IInputLayout() {



		}



		/**
		 *	Release Method
		 */
		void IInputLayout::Release() {

			delete this;

		}



		/**
		 *	Create Methods
		 */
		IInputLayout* IInputLayout::Create(IDevice* device, const std::vector<InputLayoutElementDesc>& desc, IVertexShader* vshader) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::InputLayout(device, desc, vshader);

				break;

			case DIRECTX12_API_FLAG:

				break;

			case VULKAN_API_FLAG:

				break;

			case OPENGL_API_FLAG:

				break;

			default:
				break;
			}

			return nullptr;
		}



		/**
		 *	Methods
		 */
		void IInputLayout::Apply() {



		}

	}

}

/**
 *	Include Header
 */
#include "Device.h"



/**
 *	Include Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDevice::IDevice() {



		}

		IDevice::~IDevice() {



		}



		/**
		 *	Create, Release Methods
		 */
		IDevice* IDevice::Create() {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				return nullptr;

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::Device();

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

		void IDevice::Release() {

			if (context != nullptr) {

				context->Release();

			}

			delete this;

		}

	}

}
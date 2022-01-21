
/**
 *	Include Header
 */
#include "Device.h"



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
		Device::Device() {



		}

		Device::~Device() {



		}



		/**
		 *	Create, Release Methods
		 */
		Device* Device::Create() {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				return nullptr;

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::Device();

				break;

			default:
				break;
			}

		}

		void Device::Release() {

			delete this;

		}

	}

}
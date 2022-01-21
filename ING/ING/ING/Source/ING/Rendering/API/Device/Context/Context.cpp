
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 DeviceContext
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		DeviceContext::DeviceContext(Device* device) {

			this->device = device;

		}

		DeviceContext::~DeviceContext() {



		}



		/**
		 *	Create, Release Methods
		 */
		DeviceContext* DeviceContext::Create(Device* device) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				return nullptr;

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::DeviceContext(device);

				break;

			default:
				break;
			}

		}

		void DeviceContext::Release() {

			delete this;

		}

	}

}
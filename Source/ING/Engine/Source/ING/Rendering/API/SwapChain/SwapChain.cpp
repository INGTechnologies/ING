
/**
 *	Include Header
 */
#include "SwapChain.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include SwapChain Manager
 */
#include <ING/Rendering/API/SwapChain/Manager/Manager.h>



/**
 *	Include DirectX11 SwapChain
 */
#include <ING/Rendering/API/DirectX11/SwapChain/SwapChain.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SwapChain::SwapChain(Device* device, Window* window) {

			this->device = device;

			this->window = window;

			SwapChainManager::GetInstance()->AddSwapChain(this);

		}

		SwapChain::~SwapChain() {



		}



		/**
		 *	Create, Release Methods
		 */
		SwapChain* SwapChain::Create(Device* device, Window* window) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::SwapChain(device, window);

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

		void SwapChain::Release() {

			SwapChainManager::GetInstance()->RemoveSwapChain(node);

			delete this;

		}

	}

}
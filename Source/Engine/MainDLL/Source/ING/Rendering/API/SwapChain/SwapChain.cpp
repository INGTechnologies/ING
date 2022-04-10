
/**
 *	Include Header
 */
#include "SwapChain.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 SwapChain
 */
#include <ING/Rendering/API/DirectX11/SwapChain/SwapChain.h>



/**
 *	Include RenderTargetView
 */
#include <ING/Rendering/API/View/RenderTargetView/RenderTargetView.h>



/**
 *	Include Texture2D
 */
#include <ING/Rendering/API/Resource/Texture2D/Texture2D.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include WindowEvent
 */
#include <ING/Window/Event/Event.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include WindowResizeEvent
 */
#include <ING/Window/Event/Resize/Resize.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		ISwapChain::ISwapChain(IDevice* device, Window* window) :
			node(0),
			window(0),
			renderTargetView(0),
			device(0)
		{

			this->device = device;

			this->window = window;

			renderTargetView = IRenderTargetView::Create(device);

			InitEvents();

		}

		ISwapChain::~ISwapChain() {



		}



		/**
		 *	Create, InitEvents, Release Methods
		 */
		ISwapChain* ISwapChain::Create(IDevice* device, Window* window) {

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

		void ISwapChain::InitEvents() {

			window->GetEvent("RESIZE")->AddListener([](Event* event) {

				ISwapChain* swapChain = ((WindowEvent*)event)->GetWindow()->GetScreen()->GetSwapChain();

				WindowResizeEvent* resizeEvent = (WindowResizeEvent*)event;

				swapChain->Resize(resizeEvent->newWidth, resizeEvent->newHeight);

			});

		}

		void ISwapChain::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void ISwapChain::Resize(unsigned int width, unsigned int height) {



		}

		void ISwapChain::Present() {



		}

	}

}
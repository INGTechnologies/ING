
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
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SwapChain::SwapChain(Device* device, Window* window) {

			this->device = device;

			this->window = window;

			renderTargetView = RenderTargetView::Create();

			renderTargetView->SetResource(Texture2D::Create());

			InitEvents();

		}

		SwapChain::~SwapChain() {



		}



		/**
		 *	Create, InitEvents, Release Methods
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

		void SwapChain::InitEvents() {

			window->GetEvent("RESIZE")->AddListener([](Event* event) {

				SwapChain* swapChain = ((WindowEvent*)event)->GetWindow()->GetScreen()->GetSwapChain();

			});

		}

		void SwapChain::Release() {

			delete this;

		}

	}

}
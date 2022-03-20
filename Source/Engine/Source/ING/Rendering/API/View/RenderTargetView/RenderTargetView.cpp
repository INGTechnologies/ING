
/**
 *	Include Header
 */
#include "RenderTargetView.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 RenderTargetView
 */
#include <ING/Rendering/API/DirectX11/View/RenderTargetView/RenderTargetView.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IRenderTargetView::IRenderTargetView(IDevice* device) : IView(device) {



		}

		IRenderTargetView::~IRenderTargetView() {



		}



		/**
		 *	Release Method
		 */
		IRenderTargetView* IRenderTargetView::Create(IDevice* device) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::RenderTargetView(device);

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

		void IRenderTargetView::Release() {

			delete this;

		}

	}

}
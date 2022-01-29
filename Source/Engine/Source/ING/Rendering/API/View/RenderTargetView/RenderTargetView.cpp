
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
		RenderTargetView::RenderTargetView() {



		}

		RenderTargetView::~RenderTargetView() {



		}



		/**
		 *	Release Method
		 */
		RenderTargetView* RenderTargetView::Create() {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::RenderTargetView();

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

		void RenderTargetView::Release() {

			delete this;

		}

	}

}
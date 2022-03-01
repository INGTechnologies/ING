
/**
 *	Include Header
 */
#include "RenderTargetView.h"



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			RenderTargetView::RenderTargetView(Rendering::Device* device) : Rendering::RenderTargetView(device)
			{



			}

			RenderTargetView::~RenderTargetView() {



			}



			/**
			 *	Release Method
			 */
			void RenderTargetView::Release() {

				Rendering::RenderTargetView::Release();

			}

		}

	}

}
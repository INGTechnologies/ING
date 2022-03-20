
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
			RenderTargetView::RenderTargetView(IDevice* device) : IRenderTargetView(device) {



			}

			RenderTargetView::~RenderTargetView() {



			}



			/**
			 *	Release Method
			 */
			void RenderTargetView::Release() {

				Rendering::IRenderTargetView::Release();

			}

		}

	}

}
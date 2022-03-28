
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
			RenderTargetView::RenderTargetView(IDevice* device) : 
				IRenderTargetView(device),
			
				d3d11RenderTargetView(0)
			{



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
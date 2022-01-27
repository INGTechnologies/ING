
/**
 *	Include Header
 */
#include "RenderTargetView.h"



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
		void RenderTargetView::Release() {

			delete this;

		}

	}

}
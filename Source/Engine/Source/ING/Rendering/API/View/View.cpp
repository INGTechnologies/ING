
/**
 *	Include Header
 */
#include "View.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IView::IView	(IDevice* device) {

			this->device = device;

		}

		IView::~IView	() {



		}



		/**
		 *	Release Method
		 */
		void IView::Release() {

			delete this;

		}

	}

}
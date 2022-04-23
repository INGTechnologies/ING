
/**
 *	Include Header
 */
#include "View.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IView::IView	(IDevice* device) :
			resource(0),
			device(0)
		{

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
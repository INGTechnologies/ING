
/**
 *	Include Header
 */
#include "Resource.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Resource::Resource(Rendering::Device* device) {

			this->device = device;

		}

		Resource::~Resource() {



		}



		/**
		 *	Release Method
		 */
		void Resource::Release() {

			delete this;

		}

	}

}
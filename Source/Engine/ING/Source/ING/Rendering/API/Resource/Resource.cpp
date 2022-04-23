
/**
 *	Include Header
 */
#include "Resource.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IResource::IResource(IDevice* device) : device(0) {

			this->device = device;

		}

		IResource::~IResource() {



		}



		/**
		 *	Release Method
		 */
		void IResource::Release() {

			delete this;

		}

	}

}
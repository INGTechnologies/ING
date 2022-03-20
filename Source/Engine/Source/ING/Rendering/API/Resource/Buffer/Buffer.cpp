
/**
 *	Include Header
 */
#include "Buffer.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IBuffer::IBuffer	(IDevice* device) : IResource(device) {



		}

		IBuffer::~IBuffer	() {



		}



		/**
		 *	Release Method
		 */
		void IBuffer::Release() {

			delete this;

		}

	}

}
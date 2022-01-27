
/**
 *	Include Header
 */
#include "Buffer.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Buffer::Buffer() {



		}

		Buffer::~Buffer() {



		}



		/**
		 *	Release Method
		 */
		void Buffer::Release() {

			delete this;

		}

	}

}
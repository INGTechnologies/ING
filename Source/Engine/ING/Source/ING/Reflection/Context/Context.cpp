
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Context::Context()
		{



		}

		Context::~Context() {



		}



		/**
		 *	Release Methods
		 */
		void Context::Release() {
			


			delete this;
		}

	}

}
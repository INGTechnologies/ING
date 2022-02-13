
/**
 *	Include Header
 */
#include "System.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		System::System() {



		}

		System::~System() {



		}



		/**
		 *	Release Methods
		 */
		void System::Release() {

			delete this;

		}

	}

}
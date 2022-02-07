
/**
 *	Include Header
 */
#include "Component.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Component::Component() {



		}

		Component::~Component() {



		}



		/**
		 *	Release Methods
		 */
		void Component::Release() {

			delete this;

		}

	}

}
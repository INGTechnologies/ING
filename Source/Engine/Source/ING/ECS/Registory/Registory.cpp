
/**
 *	Include Header
 */
#include "Registory.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Registory::Registory() {



		}

		Registory::~Registory() {



		}



		/**
		 *	Release Methods
		 */
		void Registory::Release() {

			delete this;

		}

	}

}
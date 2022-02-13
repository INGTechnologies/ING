
/**
 *	Include Header
 */
#include "Repository.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Repository::Repository() {



		}

		Repository::~Repository() {



		}



		/**
		 *	Release Methods
		 */
		void Repository::Release() {

			delete this;

		}

	}

}

/**
 *	Include Header
 */
#include "Procedure.h"



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IProcedure::IProcedure() {



		}

		IProcedure::~IProcedure() {



		}



		/**
		 *	Release Methods
		 */
		void IProcedure::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IProcedure::Invoke() {

			Specify<>()->Invoke();

		}

	}

}
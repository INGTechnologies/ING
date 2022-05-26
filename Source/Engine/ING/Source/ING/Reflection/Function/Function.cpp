
/**
 *	Include Header
 */
#include "Function.h"



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IFunction::IFunction() {



		}

		IFunction::~IFunction() {



		}



		/**
		 *	Release Methods
		 */
		void IFunction::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IFunction::Invoke() {

			return Specify<void>()->Invoke();

		}

	}

}
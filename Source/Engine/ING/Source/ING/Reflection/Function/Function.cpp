
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
		RType::Void IFunction::Invoke() {

			return Specify<RType::Void>()->Invoke();

		}

	}

}
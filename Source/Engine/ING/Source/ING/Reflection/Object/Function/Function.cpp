
/**
 *	Include Header
 */
#include "Function.h"



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IObjectFunction::IObjectFunction(void* object) :
			object(object)
		{



		}

		IObjectFunction::~IObjectFunction() {



		}



		/**
		 *	Release Methods
		 */
		void IObjectFunction::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		RType::Void IObjectFunction::Invoke() {

			return Specify<RType::Void>()->Invoke();

		}

	}

}
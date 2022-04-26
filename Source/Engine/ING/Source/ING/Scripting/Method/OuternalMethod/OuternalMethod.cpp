
/**
 *	Include Header
 */
#include "OuternalMethod.h"



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IOuternalMethod::IOuternalMethod(IContext* context, IMethodContainer* container) :
			IMethod(context, container)
		{



		}

		IOuternalMethod::~IOuternalMethod()
		{



		}



		/**
		 *	Release Method
		 */
		void IOuternalMethod::Release() {

			IMethod::Release();

		}



		/**
		 *	Methods
		 */
		void* IOuternalMethod::Execute(void* object, void** params) {



			return 0;
		}

	}

}

/**
 *	Include Header
 */
#include "InternalMethod.h"



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IInternalMethod::IInternalMethod(IContext* context, IMethodContainer* container) :
			IMethod(context, container)
		{



		}

		IInternalMethod::~IInternalMethod()
		{



		}



		/**
		 *	Release Method
		 */
		void IInternalMethod::Release() {

			IMethod::Release();

		}

	}

}
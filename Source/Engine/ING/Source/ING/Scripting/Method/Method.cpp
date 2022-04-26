
/**
 *	Include Header
 */
#include "Method.h"



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IMethod::IMethod(IContext* context, IMethodContainer* container) :
			context(context),
			container(container)
		{



		}

		IMethod::~IMethod()
		{



		}



		/**
		 *	Release Method
		 */
		void IMethod::Release() {

			delete this;

		}

	}

}

/**
 *	Include Header
 */
#include "InternalMethod.h"



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			InternalMethod::InternalMethod(IContext* context, IMethodContainer* container) :
				IInternalMethod(context, container),

				assembly(0)
			{



			}

			InternalMethod::~InternalMethod()
			{



			}



			/**
			 *	Release Method
			 */
			void InternalMethod::Release() {

				IInternalMethod::Release();

			}

		}

	}

}
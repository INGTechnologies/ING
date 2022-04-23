
/**
 *	Include Header
 */
#include "OuternalMethod.h"



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			OuternalMethod::OuternalMethod(IContext* context, IMethodContainer* container) :
				IOuternalMethod(context, container),

				assembly(0)
			{



			}

			OuternalMethod::~OuternalMethod()
			{



			}



			/**
			 *	Release Method
			 */
			void OuternalMethod::Release() {

				IOuternalMethod::Release();

			}



			/**
			 *	Methods
			 */
			void* OuternalMethod::Execute(void* object, void** params) {

				mono_runtime_invoke(monoMethod, object, params, 0);

				return 0;
			}

		}

	}

}
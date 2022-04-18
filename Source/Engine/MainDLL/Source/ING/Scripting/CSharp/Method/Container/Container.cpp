
/**
 *	Include Header
 */
#include "Container.h"



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			MethodContainer::MethodContainer(Assembly* assembly, IContext* context) :
				IMethodContainer(context),

				assembly(assembly)
			{



			}

			MethodContainer::~MethodContainer()
			{



			}



			/**
			 *	Release Method
			 */
			void MethodContainer::Release() {

				IMethodContainer::Release();

			}

		}

	}

}
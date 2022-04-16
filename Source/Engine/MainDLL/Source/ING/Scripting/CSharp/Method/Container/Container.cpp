
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
			MethodContainer::MethodContainer(IContext* context) :
				IMethodContainer(context)
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
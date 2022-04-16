
/**
 *	Include Header
 */
#include "Container.h"



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IMethodContainer::IMethodContainer(IContext* context) :
			context(context)
		{



		}

		IMethodContainer::~IMethodContainer()
		{

			

		}



		/**
		 *	Release Method
		 */
		void IMethodContainer::Release() {

			delete this;

		}

	}

}
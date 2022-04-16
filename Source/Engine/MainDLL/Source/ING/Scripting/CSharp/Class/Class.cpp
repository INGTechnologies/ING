
/**
 *	Include Header
 */
#include "Class.h"



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Class::Class(IContext* context) :
				MethodContainer(context),

				assembly(0)
			{



			}

			Class::~Class()
			{



			}



			/**
			 *	Release Method
			 */
			void Class::Release() {

				MethodContainer::Release();

			}

		}

	}

}
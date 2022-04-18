
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
			Class::Class(Assembly* assembly, IContext* context) :
				MethodContainer(assembly, context)
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
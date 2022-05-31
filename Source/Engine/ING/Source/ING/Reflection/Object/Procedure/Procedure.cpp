
/**
 *	Include Header
 */
#include "Procedure.h"



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IObjectProcedure::IObjectProcedure(C_Object* object) :
			object(object)
		{



		}

		IObjectProcedure::~IObjectProcedure() {



		}



		/**
		 *	Release Methods
		 */
		void IObjectProcedure::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IObjectProcedure::Invoke() {

			Specify<>()->Invoke();

		}

	}

}
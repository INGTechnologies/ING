
/**
 *	Include Header
 */
#include "Object.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Namespace
 */
#include <ING/Reflection/Namespace/Namespace.h>



/**
 *	Include Type
 */
#include <ING/Reflection/Type/Type.h>



/**
 *	Include Class
 */
#include <ING/Reflection/Type/Class/Class.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IObject::IObject(IClass* _class) :
			_class(_class)
		{



		}

		IObject::~IObject() {



		}



		/**
		 *	Release Methods
		 */
		void IObject::Release() {

			delete this;
		}

	}

}
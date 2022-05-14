
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
 *	Include ClassType
 */
#include <ING/Reflection/Type/ClassType/ClassType.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IObject::IObject(IClassType* _class) :
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
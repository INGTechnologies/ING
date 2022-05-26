
/**
 *	Include Header
 */
#include "Class.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Namespace
 */
#include <ING/Reflection/Namespace/Namespace.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IClass::IClass(const String& name, Namespace* _namespace) :
			IType(name, _namespace)
		{

			GetNamespace()->AddType(this);

		}

		IClass::~IClass() {



		}



		/**
		 *	Release Methods
		 */
		void IClass::Release() {

			GetNamespace()->RemoveType(this);

			IType::Release();
		}



		/**
		 *	Methods
		 */
		IObject* IClass::ICreateInstance() {

			return 0;
		}

	}

}

/**
 *	Include Header
 */
#include "ClassType.h"



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
		IClassType::IClassType(const String& name, Namespace* _namespace) :
			IType(name, _namespace)
		{

			GetNamespace()->AddType(this);

		}

		IClassType::~IClassType() {



		}



		/**
		 *	Release Methods
		 */
		void IClassType::Release() {

			GetNamespace()->RemoveType(this);

			IType::Release();
		}



		/**
		 *	Methods
		 */
		IObject* IClassType::CreateInstance() {


			return 0;
		}

	}

}
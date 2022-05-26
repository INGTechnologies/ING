
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
#include <ING/Reflection/Class/Class.h>



/**
 *	Include Object Function
 */
#include <ING/Reflection/Object/Function/Function.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IObject::IObject(IClass* _class) :
			ING::IObject(),
			_class(_class)
		{

			for (auto item : _class->GetName2MemberMap()) {

				if (!(item.second.isProperty)) {

					if(name2Function.find(item.second.name) != name2Function.end()) {

						name2Function[item.second.name]->Release();

					}

					name2Function[item.second.name] = item.second.functionCreator(this);

				}

			}

		}

		IObject::~IObject() {



		}



		/**
		 *	Release Methods
		 */
		void IObject::Release() {

			for (auto item : name2Function) {

				item.second->Release();

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void* IObject::GetPropertyPointer(const String& name) {

			return ((char*)this) + _class->GetMember(name).offsetInBytes;

		}

	}

}

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



/**
 *	Include Reflection Object
 */
#include <ING/Reflection/Object/Object.h>



/**
 *	Include Reflection Object Function
 */
#include <ING/Reflection/Object/Function/Function.h>



/**
 *	Include Reflection Context
 */
#include <ING/Reflection/Context/Context.h>



/**
 *	Include Object
 */
#include <ING/Object/Object.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IClass::IClass(const String& name, Namespace* _namespace, IClass* base) :
			IType(name, _namespace),

			base(base),

			context(_namespace->GetContext())
		{

			if (base == 0) {

				base = context->GetClass(IType::TypeInfoToFullName(typeid(Reflection::IObject)));

				if (base == this) {

					base = 0;

				}

			}



			GetNamespace()->AddType(this);



			/**
			 *	Add Base's Members
			 */
			if (base != 0) {

				for (auto item : base->name2MemberMap) {

					SetMember(item.second);

				}

			}



			/**
			 *	Add Reflection::IObject Members
			 */
			if (base == 0) {

				SetMember({

					0,

					(unsigned int)GetMemberOffset(&ING::IObject::id),

					IType::TypeInfoToFullName(typeid(ObjectId)),

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction* {return 0; },

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"id",

					CLASS_MEMBER_ACCESS_PRIVATE,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					1,

					0,

					"",

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction* {

						return new ING::Reflection::ObjectFunction<Reflection::IObject, &Reflection::IObject::GetId,ObjectId>((Reflection::IObject*)object);
					},

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"GetId",

					CLASS_MEMBER_ACCESS_PUBLIC,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					0,

					(unsigned int)GetMemberOffset(&ING::Reflection::IObject::_class),

					IType::TypeInfoToFullName(typeid(ING::Reflection::IClass*)),

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction* {return 0; },

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"_class",

					CLASS_MEMBER_ACCESS_PRIVATE,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					1,

					0,

					"",

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction* {

						return new ING::Reflection::ObjectFunction<Reflection::IObject, &Reflection::IObject::GetClass, IClass*>((Reflection::IObject*)object);
					},

					[](ING::Reflection::IObject* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"GetClass",

					CLASS_MEMBER_ACCESS_PUBLIC,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

			}

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
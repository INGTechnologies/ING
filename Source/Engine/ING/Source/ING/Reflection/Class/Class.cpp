
/**
 *	Include Header
 */
#include "Class.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>



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

			context(_namespace->GetContext()),

			instanceConstructorCaller(0)
		{

			if (base == 0) {

				base = context->GetClass(IType::TypeInfoToFullName(typeid(Reflection::C_Object)));

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

					if (item.second.memberType != 0) {

						SetMember(item.second);

					}
					else {

						if (item.second.access == CLASS_MEMBER_ACCESS_PUBLIC || item.second.access == CLASS_MEMBER_ACCESS_PROTECTED) {

							SetMember(item.second);

						}

					}

				}

			}



			/**
			 *	Add Reflection::C_Object Members
			 */
			if (base == 0) {

				SetMember({

					0,

					TYPE_GROUP_NONE,

					(unsigned int)GetMemberOffset(&ING::IObject::id),

					IType::TypeInfoToFullName(typeid(ObjectId)),

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction* {return 0; },

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"id",

					CLASS_MEMBER_ACCESS_PRIVATE,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					1,

					TYPE_GROUP_NONE,

					0,

					"",

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction* {

						return new ING::Reflection::ObjectFunction<Reflection::C_Object, &Reflection::C_Object::GetId,ObjectId>((Reflection::C_Object*)object);
					},

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"GetId",

					CLASS_MEMBER_ACCESS_PUBLIC,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					0,

					TYPE_GROUP_NONE,

					(unsigned int)GetMemberOffset(&ING::Reflection::C_Object::_class),

					IType::TypeInfoToFullName(typeid(ING::Reflection::IClass*)),

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction* {return 0; },

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure* {return 0; },

					"_class",

					CLASS_MEMBER_ACCESS_PRIVATE,

					CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE

					});

				SetMember({

					1,

					TYPE_GROUP_NONE,

					0,

					"",

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction* {

						return new ING::Reflection::ObjectFunction<Reflection::C_Object, &Reflection::C_Object::GetClass, IClass*>((Reflection::C_Object*)object);
					},

					[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure* {return 0; },

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

			if (instanceConstructorCaller != 0) {

				instanceConstructorCaller->Release();

			}

			IType::Release();
		}



		/**
		 *	Methods
		 */
		C_Object* IClass::IMalloc() {

			return 0;
		}

		IObjectProcedure* IClass::GetConstructor(C_Object* object) {

			return object->GetProcedure("Constructor");

		}

		C_Object* IClass::ICreateInstance() {

			return 0;
		}

	}

}
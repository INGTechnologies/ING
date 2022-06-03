
/**
 *	Include Header
 */
#include "Struct.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Namespace
 */
#include <ING/Reflection/Namespace/Namespace.h>



/**
 *	Include Reflection Context
 */
#include <ING/Reflection/Context/Context.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IStruct::IStruct(const String& name, Namespace* _namespace, IStruct* base, unsigned int size) :
			IType(name, _namespace),

			base(base),

			context(_namespace->GetContext())
		{

			GetNamespace()->AddType(this);



			/**
			 *	Add Base's Members
			 */
			if (base != 0) {

				for (auto item : base->name2MemberMap) {

					SetMember(item.second);

				}

			}

		}

		IStruct::~IStruct() {



		}



		/**
		 *	Release Methods
		 */
		void IStruct::Release() {

			GetNamespace()->RemoveType(this);

			IType::Release();
		}

	}

}
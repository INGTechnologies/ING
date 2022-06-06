
/**
 *	Include Header
 */
#include "Context.h"



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
 *	Include Object
 */
#include <ING/Reflection/Object/Object.h>



/**
 *	Include Struct
 */
#include <ING/Reflection/Struct/Struct.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Context::Context() :
			globalNamespace(0),
			objectClass(0)
		{

			globalNamespace = new Namespace("", this);

			objectClass = new Class<Reflection::C_Object>(
				IType::FullNameToBaseName(typeid(Reflection::C_Object)),
				CreateNamespace(IType::FullNameToNamespaceName(typeid(Reflection::C_Object)))
			);

		}

		Context::~Context() {



		}



		/**
		 *	Release Methods
		 */
		void Context::Release() {
			
			globalNamespace->Release();

			delete this;
		}



		/**
		 *	Methods
		 */
		Namespace*	Context::CreateNamespace(const String& fullName) {

			if (fullName == "") return globalNamespace;

			NamespacePath path = Namespace::FullNameToPath(fullName);

			Namespace* currentNamespace = globalNamespace;

			for (auto& item : path) {

				if (!currentNamespace->IsHasChild(item)) {

					currentNamespace->AddChild(
					
						new Namespace(item, this)
					
					);

				}

				currentNamespace = currentNamespace->GetChild(item);

			}

			return currentNamespace;
		}

		Namespace*	Context::GetNamespace(const String& fullName) {

			return CreateNamespace(fullName);

		}

		IClass*		Context::GetClass(const String& fullName) {

			String namespaceName = IType::FullNameToNamespaceName(fullName);
			String className = IType::FullNameToBaseName(fullName);

			Namespace* _namespace = GetNamespace(namespaceName);

			if (_namespace == 0) return 0;

			if (!_namespace->IsHasType(className)) return 0;

			return (IClass*)(_namespace->GetType(className));

		}

		IStruct*	Context::GetStruct(const String& fullName) {

			String namespaceName = IType::FullNameToNamespaceName(fullName);
			String structName = IType::FullNameToBaseName(fullName);

			Namespace* _namespace = GetNamespace(namespaceName);

			if (_namespace == 0) return 0;

			if (!_namespace->IsHasType(structName)) return 0;

			return (IStruct*)(_namespace->GetType(structName));

		}

		bool		Context::IsHasType(const String& fullName) {

			String namespaceName = IType::FullNameToNamespaceName(fullName);
			String typeName = IType::FullNameToBaseName(fullName);

			Namespace* _namespace = GetNamespace(namespaceName);

			if (_namespace == 0) return false;

			return _namespace->IsHasType(typeName);

		}

	}

}
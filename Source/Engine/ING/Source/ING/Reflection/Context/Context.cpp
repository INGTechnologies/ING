
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

			objectClass = new Class<Reflection::IObject>(
				IType::FullNameToBaseName(typeid(Reflection::IObject)),
				CreateNamespace(IType::FullNameToNamespaceName(typeid(Reflection::IObject)))
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
		Namespace* Context::CreateNamespace(const String& fullName) {

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

		Namespace* Context::GetNamespace(const String& fullName) {

			return CreateNamespace(fullName);

		}

		IClass* Context::GetClass(const String& fullName) {

			String namespaceName = IType::FullNameToNamespaceName(fullName);
			String className = IType::FullNameToBaseName(fullName);

			return (IClass*)(GetNamespace(namespaceName)->GetType(className));

		}

	}

}
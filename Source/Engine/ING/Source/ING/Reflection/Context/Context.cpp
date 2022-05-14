
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
 *	Include ClassType
 */
#include <ING/Reflection/Type/ClassType/ClassType.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Context::Context() :
			globalNamespace(0)
		{

			globalNamespace = new Namespace("", this);

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

		IClassType* Context::GetClass(const String& fullName) {

			String namespaceName = IType::FullNameToNamespaceName(fullName);
			String className = IType::FullNameToBaseName(fullName);

			return (IClassType*)(GetNamespace(namespaceName)->GetType(className));

		}

	}

}

/**
 *	Include Header
 */
#include "Namespace.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Type
 */
#include <ING/Reflection/Type/Type.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Namespace::Namespace(const String& name, Context* context) :
			name(name),
			isGlobal(name == ""),
			parent(0),
			context(context)
		{



		}

		Namespace::~Namespace() {



		}



		/**
		 *	Release Methods
		 */
		void Namespace::Release() {

			if (parent != 0) {

				parent->RemoveChild(this);

			}
			
			for (auto item = name2TypeMap.begin(); item != name2TypeMap.end();) {

				(item++)->second->Release();

			}

			for (auto item = name2ChildMap.begin(); item != name2ChildMap.end();) {

				(item++)->second->Release();

			}

			delete this;
		}



		/**
		 *	Properties
		 */
		void Namespace::SetContext(Context* context) {

			this->context = context;

			for (auto item : name2ChildMap) {

				item.second->SetContext(context);

			}

		}



		/**
		 *	Methods
		 */
		NamespacePath Namespace::FullNameToPath(const String& fullName) {

			String currentName;

			NamespacePath namespacePath;

			for (unsigned int i = 0; i < fullName.length(); ++i) {

				if (fullName[i] == ':') {

					i += 1;

					namespacePath.push_back(currentName);

					currentName = "";

					continue;

				}

				currentName += fullName[i];

			}

			namespacePath.push_back(currentName);

			return namespacePath;
		}

		void Namespace::AddChild	(Namespace* _namespace) {

			name2ChildMap[_namespace->name] = _namespace;

			_namespace->parent = this;

			_namespace->SetContext(context);

		}

		void Namespace::RemoveChild	(Namespace* _namespace) {

			_namespace->parent = 0;

			name2ChildMap.erase(_namespace->GetName());

			_namespace->SetContext(0);

		}

		void Namespace::RemoveChild	(const String& name) {

			RemoveChild(GetChild(name));

		}

		void Namespace::AddType(IType* _type) {

			if (_type->GetNamespace() != this) return;

			name2TypeMap[_type->GetName()] = _type;

		}

		void Namespace::RemoveType(IType* _type) {

			if (!IsHasType(_type->GetName())) return;

			name2TypeMap.erase(_type->GetName());

		}

	}

}
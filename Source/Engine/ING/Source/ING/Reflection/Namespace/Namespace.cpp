
/**
 *	Include Header
 */
#include "Namespace.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Namespace::Namespace(const String& name, bool isGlobal) :
			name(name),
			isGlobal(isGlobal)
		{



		}

		Namespace::Namespace(const String& name) :
			Namespace(name, false)
		{



		}

		Namespace::~Namespace() {



		}



		/**
		 *	Release Methods
		 */
		void Namespace::Release() {
			


			delete this;
		}



		/**
		 *	Methods
		 */
		Namespace* Namespace::Create(const String& fullName) {



			return 0;
		}

		void Namespace::AddChild	(Namespace* _namespace) {

			name2ChildMap[_namespace->name] = _namespace;

			_namespace->parent = this;

		}

		void Namespace::RemoveChild	(Namespace* _namespace) {

			_namespace->parent = 0;

			name2ChildMap.erase(_namespace->GetName());

		}

		void Namespace::RemoveChild	(const String& name) {

			RemoveChild(GetChild(name));

		}

	}

}
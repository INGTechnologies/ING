
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Language
 */
#include <ING/Scripting/Language/Language.h>



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IContext::IContext(const String& name, ILanguage* language) :
			name(name),
			language(language)
		{

			language->AddContext(this);

		}

		IContext::~IContext()
		{



		}



		/**
		 *	Release Method
		 */
		void IContext::Release() {

			GetLanguage()->RemoveContext(this);

			delete this;
			
		}



		/**
		 *	Methods
		 */
		IOuternalMethod* IContext::GetOuternalMethod(IMethodContainer* container, const String& name) {



			return 0;
		}

		void IContext::Load() {



		}

		void IContext::Unload() {



		}

		void IContext::Reload() {



		}

	}

}
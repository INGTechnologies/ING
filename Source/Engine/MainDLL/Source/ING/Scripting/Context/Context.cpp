
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IContext::IContext(ILanguage* language) :
			language(language)
		{



		}

		IContext::~IContext()
		{



		}



		/**
		 *	Release Method
		 */
		void IContext::Release() {

			delete this;
			
		}

	}

}
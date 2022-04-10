
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
		IContext::IContext(const std::string& name, ILanguage* language) :
			name(name),
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
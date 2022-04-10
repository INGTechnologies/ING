
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

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Context::Context(ILanguage* language) :
				IContext(language)
			{



			}

			Context::~Context()
			{



			}



			/**
			 *	Release Method
			 */
			void Context::Release() {

				IContext::Release();

			}

		}

	}

}
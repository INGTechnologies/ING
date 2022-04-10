
/**
 *	Include Header
 */
#include "Language.h"



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
		ILanguage::ILanguage()
		{



		}

		ILanguage::~ILanguage()
		{



		}



		/**
		 *	Release Method
		 */
		void ILanguage::Release() {

			delete this;
			
		}



		/**
		 *	Methods
		 */
		IContext* ILanguage::CreateContext() {

			Debug::Error("Cant Create Scripting Context");

			return 0;

		}

	}

}
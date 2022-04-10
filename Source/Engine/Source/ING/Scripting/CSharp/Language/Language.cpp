
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

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Language::Language()
			{



			}

			Language::~Language()
			{



			}



			/**
			 *	Release Method
			 */
			void Language::Release() {

				ILanguage::Release();

			}



			/**
			 *	Methods
			 */
			std::string Language::GetName() { return "CSharp"; }

		}

	}

}

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



/**
 *	Include Scripting Manager
 */
#include <ING/Scripting/Manager/Manager.h>



/**
 *	Include Scripting Context
 */
#include <ING/Scripting/Context/Context.h>



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		ILanguage::ILanguage() :
			mainContext(0)
		{



		}

		ILanguage::~ILanguage()
		{



		}



		/**
		 *	Release Method
		 */
		void ILanguage::Release() {

			mainContext->Release();

			Manager::GetInstance()->RemoveLanguage(this);

			delete this;
			
		}



		/**
		 *	Methods
		 */
		void		ILanguage::UpdateCreation() {

			mainContext = CreateContext(GetName() + String("MainContext"), true);

			Manager::GetInstance()->AddLanguage(this);

		}

		IContext*	ILanguage::CreateContext(const std::string& name, bool isMainContext) {

			Debug::Error("Cant Create Scripting Context");

			return 0;

		}

		IContext* ILanguage::CreateContext(const std::string& name) {

			return CreateContext(name, false);

		}

	}

}
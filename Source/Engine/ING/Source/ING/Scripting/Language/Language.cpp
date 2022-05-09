
/**
 *	Include Header
 */
#include "Language.h"



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
		 *	Init, Release Method
		 */
		void ILanguage::Init() {

			mainContext = CreateContext("Main", true);

			Manager::GetInstance()->AddLanguage(this);

		}

		void ILanguage::Release() {

			if(mainContext != 0)
				mainContext->Release();

			Manager::GetInstance()->RemoveLanguage(this);

			delete this;
			
		}



		/**
		 *	Methods
		 */
		void		ILanguage::AddContext(IContext* context) {

			name2ContextMap[context->GetName()] = context;

		}

		void		ILanguage::RemoveContext(IContext* context) {

			name2ContextMap.erase(context->GetName());

		}

		IContext*	ILanguage::CreateContext(const String& name, bool isMainContext) {

			Debug::Error("Cant Create Scripting Context");

			return 0;

		}

		IContext* ILanguage::CreateContext(const String& name) {

			return CreateContext(name, false);

		}

	}

}

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
		ILanguage::ILanguage()
		{



		}

		ILanguage::~ILanguage()
		{



		}



		/**
		 *	Init, Release Method
		 */
		void ILanguage::Init() {

			Manager::GetInstance()->AddLanguage(this);

		}

		void ILanguage::Release() {

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

		IContext*	ILanguage::CreateContext(const String& name) {

			Debug::Error("Cant Create Scripting Context");

			return 0;

		}

	}

}
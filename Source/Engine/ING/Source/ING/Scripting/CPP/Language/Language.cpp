
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
 *	Include CSharp Context
 */
#include <ING/Scripting/CSharp/Context/Context.h>



/**
 *	Include Scripting Manager
 */
#include <ING/Scripting/Manager/Manager.h>



#define MINI_CASE_SENSITIVE

/**
 *	Include mIni
 */
#include <ING/Configuration/mINI/src/mini/ini.h>

#undef MINI_CASE_SENSITIVE



#include <filesystem>



namespace ING {

	namespace Scripting {

		namespace CPP {

			/**
			 *	Constructors And Destructor
			 */
			Language::Language() :
				ILanguage()
			{



			}

			Language::~Language()
			{



			}



			/**
			 *	Init, Release Method
			 */
			void Language::Init() {

				ILanguage::Init();

			}

			void Language::Release() {



				ILanguage::Release(); 

			}



			/**
			 *	Methods
			 */
			String Language::GetName() { return "CPP"; }

			IContext*	Language::CreateContext(const String& name, bool isMainContext) {

				return 0;

			}

		}

	}

}
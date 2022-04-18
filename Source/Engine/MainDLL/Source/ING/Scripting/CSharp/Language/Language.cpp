
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
 *	Include CSharp Context
 */
#include <ING/Scripting/CSharp/Context/Context.h>



/**
 *	Include Scripting Manager
 */
#include <ING/Scripting/Manager/Manager.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Language::Language() :
				ILanguage()
			{

				mono_set_dirs(".", ".");

				rootDomain = mono_jit_init((GetName() + String("RootDomain")).c_str());

				UpdateCreation();				

			}

			Language::~Language()
			{



			}



			/**
			 *	Release Method
			 */
			void Language::Release() {

				MonoDomain* rootDomain = this->rootDomain;

				ILanguage::Release();

				mono_jit_cleanup(rootDomain);

			}



			/**
			 *	Methods
			 */
			std::string Language::GetName() { return "CSharp"; }

			IContext*	Language::CreateContext(const std::string& name, bool isMainContext) {

				if (mainContext != 0 && isMainContext == true) {

					Debug::Warning(GetName() + String(" Main Context Created"));

					return mainContext;

				}

				return new CSharp::Context(name, this, isMainContext);

			}

		}

	}

}
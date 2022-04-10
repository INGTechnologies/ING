
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
			Context::Context(const std::string& name, ILanguage* language) :
				IContext(name, language),

				domain(0)
			{

				mono_set_dirs(".",".");

				domain = mono_jit_init(name.c_str());

				if (domain == 0) {

					Debug::Error("Cant Create CSharp Scripting Context");

					Release();

					return;

				}

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
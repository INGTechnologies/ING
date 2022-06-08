
/**
 *	Include Header
 */
#include "Module.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructor And Destructors
			 */
			ApplicationModule::ApplicationModule(const String& name) :
				IApplicationModule(name)
			{



			}

			ApplicationModule::~ApplicationModule() {



			}



			/**
			 *	Release Methods
			 */
			void ApplicationModule::Release() {

				IApplicationModule::Release();

			}

		}

	}

}
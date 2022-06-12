
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
			ApplicationModule::ApplicationModule(IApplication* application) :
				IApplicationModule("ING.Rendering.StandardRP", application)
			{

				AddDependency("ING");

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

/**
 *	Include Header
 */
#include "Module.h"



namespace ING {

	namespace StandardRP {

		/**
		 *	Constructor And Destructors
		 */
		ApplicationModule::ApplicationModule(IApplication* application) :
			IApplicationModule("ING.StandardRP", application)
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
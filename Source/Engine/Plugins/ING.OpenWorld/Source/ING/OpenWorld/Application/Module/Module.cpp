
/**
 *	Include Header
 */
#include "Module.h"



/**
 *	Include StandardRP Module
 */
#include <ING/StandardRP/Application/Module/Module.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



namespace ING {

	namespace OpenWorld {

		/**
		 *	Constructor And Destructors
		 */
		ApplicationModule::ApplicationModule(IApplication* application) :
			IApplicationModule("ING.OpenWorld", application)
		{

			if (!application->IsHasModule("ING.StandardRP"))
				new StandardRP::ApplicationModule(application);



			AddDependency("ING");
			AddDependency("ING.StandardRP");

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
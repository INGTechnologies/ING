
/**
 *	Include Header
 */
#include "Module.h"



/**
 *	Include Rendering StandardRP Module
 */
#include <ING/Rendering/StandardRP/Application/Module/Module.h>



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

			if (!application->IsHasModule("ING.Rendering.StandardRP"))
				new Rendering::StandardRP::ApplicationModule(application);



			AddDependency("ING");
			AddDependency("ING.Rendering.StandardRP");

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
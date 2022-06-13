
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



/**
 *	Include Canvas
 */
#include <ING/ImmediateGUI/Canvas/Canvas.h>



namespace ING {

	namespace ImmediateGUI {

		/**
		 *	Constructor And Destructors
		 */
		ApplicationModule::ApplicationModule(IApplication* application) :
			IApplicationModule("ING.ImmediateGUI", application)
		{

			if (!application->IsHasModule("ING.Rendering.StandardRP"))
				new Rendering::StandardRP::ApplicationModule(application);



			RegisterType<ImmediateGUI::C_Canvas>(0);



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

/**
 *	Include Header
 */
#include "Module.h"



/**
 *	Include StandardRP Pipeline
 */
#include <ING/StandardRP/Pipeline/Pipeline.h>



/**
 *	Include StandardRP Renderer
 */
#include <ING/StandardRP/Renderer/Renderer.h>



namespace ING {

	namespace StandardRP {

		/**
		 *	Constructor And Destructors
		 */
		ApplicationModule::ApplicationModule(IApplication* application) :
			IApplicationModule("ING.StandardRP", application)
		{

			RegisterType<C_Pipeline>(0);
			RegisterType<C_Renderer>(0);



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

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



/**
 *	Include StandardRP Passes
 */
#include <ING/StandardRP/Pass/DepthPrepass/DepthPrepass.h>
#include <ING/StandardRP/Pass/FinalPass/FinalPass.h>
#include <ING/StandardRP/Pass/FirstPass/FirstPass.h>
#include <ING/StandardRP/Pass/GBufferPass/GBufferPass.h>
#include <ING/StandardRP/Pass/PostProcessPass/PostProcessPass.h>
#include <ING/StandardRP/Pass/SkyPass/SkyPass.h>
#include <ING/StandardRP/Pass/TransparentPass/TransparentPass.h>
#include <ING/StandardRP/Pass/UIPass/UIPass.h>



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

			RegisterType<C_DepthPrepass>(0);
			RegisterType<C_FinalPass>(0);
			RegisterType<C_FirstPass>(0);
			RegisterType<C_GBufferPass>(0);
			RegisterType<C_PostProcessPass>(0);
			RegisterType<C_SkyPass>(0);
			RegisterType<C_TransparentPass>(0);
			RegisterType<C_UIPass>(0);



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
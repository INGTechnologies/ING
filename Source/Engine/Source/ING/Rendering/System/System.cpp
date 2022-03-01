
/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include StandardRP Pipeline
 */
#include <ING/Rendering/StandardRP/Pipeline/Pipeline.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		System::System() {



		}

		System::~System() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool System::Init() {

			defaultPipeline = new StandardRP::Pipeline("Standard Rendering Pipeline");

			targetPipeline = defaultPipeline;

			return true;
		}

		bool System::Run() {



			return true;
		}

		bool System::Release() {



			return true;
		}



		/**
		 *	Properties
		 */
		void System::SetPipeline(IPipeline* pipeline) {

			/* New Pipeline Will Be Used In Next Frame */
			targetPipeline = pipeline;

		}



		/**
		 *	Methods
		 */
		void System::FrameUpdate() {

			/* Set Pipeline */
			pipeline = targetPipeline;



			pipeline->Render(Rendering::IAPI::GetInstance()->GetDevice()->GetContext());

		}

	}
}

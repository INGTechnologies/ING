
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



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		System::System() :
			defaultPipeline(0),
			pipeline(0),
			targetPipeline(0)
		{

			Debug::Log("Start Creating Rendering::System");

			Debug::Log("Rendering::System Created");

		}

		System::~System() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool System::Init() {

			Debug::Log("Start Initializing Rendering::System");

			defaultPipeline = new StandardRP::Pipeline("Standard Rendering Pipeline");

			targetPipeline = defaultPipeline;

			isRendering = false;

			Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* e) {

				System::GetInstance()->PreUpdate();

			});

			Debug::Log("Rendering::System Initialized");

			return true;
		}

		bool System::Run() {

			Debug::Log("Start Running Rendering::System");

			return true;
		}

		bool System::Release() {

			Debug::Log("Start Releasing Rendering::System");

			delete this;

			Debug::Log("Finished Releasing Rendering::System");

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
		void System::PreUpdate() {



		}

		void System::FrameUpdate() {

			/* Set Pipeline */
			pipeline = targetPipeline;

			isRendering = true;

			pipeline->Render(Rendering::IAPI::GetInstance()->GetDevice()->GetContext());

			isRendering = false;

		}

	}
}

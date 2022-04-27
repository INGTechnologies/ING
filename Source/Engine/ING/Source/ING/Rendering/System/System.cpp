
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
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		System::System(IApplication* application) :
			IApplicationComponent(application, "Rendering::System"),

			defaultPipeline(0),
			pipeline(0),
			targetPipeline(0),

			defaultDevice(0),
			device(0),
			targetDevice(0)
		{



		}

		System::~System() {



		}



		/**
		 *	Init, Release Methods
		 */
		bool System::Init() {

			defaultPipeline = new StandardRP::Pipeline("Standard Rendering Pipeline");

			targetPipeline = defaultPipeline;

			defaultDevice = Rendering::IAPI::GetInstance()->GetDevice();

			targetDevice = defaultDevice;

			return IApplicationComponent::Init();
		}

		void System::Release() {

			IApplicationComponent::Release();

		}



		/**
		 *	Properties
		 */
		void System::SetPipeline(IPipeline* pipeline) {

			/* New Pipeline Will Be Used In Next Frame */
			targetPipeline = pipeline;

		}

		void System::SetDevice(IDevice* device) {

			/* New Device Will Be Used In Next Frame */
			targetDevice = device;

		}



		/**
		 *	Methods
		 */
		void	System::Start() {

			IApplicationComponent::Start();

		}

		void	System::PreUpdate() {

			IApplicationComponent::PreUpdate();

		}

		void	System::Update() {

			IApplicationComponent::Update();

		}

		void	System::LateUpdate() {

			IApplicationComponent::LateUpdate();

		}

		void	System::PreRender() {

			IApplicationComponent::PreRender();

		}

		void	System::Render() {

			IApplicationComponent::Render();

			pipeline = targetPipeline;
			device = targetDevice;

			pipeline->Render(device->GetImmediateContext());

		}

		void	System::LateRender() {

			IApplicationComponent::LateRender();

		}

	}
}

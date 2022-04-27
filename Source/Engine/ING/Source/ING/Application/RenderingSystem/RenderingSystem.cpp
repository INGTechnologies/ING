
/**
 *	Include Header
 */
#include "RenderingSystem.h"



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

	/**
	 *	Constructors And Destructor
	 */
	ApplicationRenderingSystem::ApplicationRenderingSystem(IApplication* application) :
		IApplicationComponent(application, "Rendering::System"),

		defaultPipeline(0),
		pipeline(0),
		targetPipeline(0),

		defaultDevice(0),
		device(0),
		targetDevice(0)
	{



	}

	ApplicationRenderingSystem::~ApplicationRenderingSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationRenderingSystem::Init() {

		defaultPipeline = new Rendering::StandardRP::Pipeline("Standard Rendering Pipeline");

		targetPipeline = defaultPipeline;

		defaultDevice = Rendering::IAPI::GetInstance()->GetDevice();

		targetDevice = defaultDevice;

		return IApplicationComponent::Init();
	}

	void ApplicationRenderingSystem::Release() {

		IApplicationComponent::Release();

	}



	/**
		*	Properties
		*/
	void ApplicationRenderingSystem::SetPipeline(Rendering::IPipeline* pipeline) {

		/* New Pipeline Will Be Used In Next Frame */
		targetPipeline = pipeline;

	}

	void ApplicationRenderingSystem::SetDevice(Rendering::IDevice* device) {

		/* New Device Will Be Used In Next Frame */
		targetDevice = device;

	}



	/**
	 *	Methods
	 */
	void	ApplicationRenderingSystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationRenderingSystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationRenderingSystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationRenderingSystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationRenderingSystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationRenderingSystem::Render() {

		IApplicationComponent::Render();

		pipeline = targetPipeline;
		device = targetDevice;

		pipeline->Render(device->GetImmediateContext());

	}

	void	ApplicationRenderingSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}

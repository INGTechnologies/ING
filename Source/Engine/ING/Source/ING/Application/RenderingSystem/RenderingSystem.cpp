
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
		IApplicationComponent(application, "RenderingSystem"),

		pipeline(0),

		device(0)
	{



	}

	ApplicationRenderingSystem::~ApplicationRenderingSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationRenderingSystem::Init() {

		pipeline = new Rendering::StandardRP::Pipeline("StandardRP.Pipeline");

		device = Rendering::IAPI::GetInstance()->GetDevice();

		return IApplicationComponent::Init();
	}

	void ApplicationRenderingSystem::Release() {

		if (pipeline != 0) {

			pipeline->Release();

		}

		IApplicationComponent::Release();

	}



	/**
	 *	Properties
	 */
	void	ApplicationRenderingSystem::ChangePipeline(Rendering::IPipeline* pipeline) {

		if (this->pipeline != 0) {

			this->pipeline->Release();

		}

		this->pipeline = pipeline;

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

		pipeline->Render(device->GetImmediateContext());

	}

	void	ApplicationRenderingSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}


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



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationRenderingSystem::ApplicationRenderingSystem(IApplication* application) :
		IApplicationComponent(application, "RenderingSystem"),

		mainPipeline(0),

		mainDevice(0)
	{



	}

	ApplicationRenderingSystem::~ApplicationRenderingSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationRenderingSystem::Init() {

		//mainPipeline = new Rendering::StandardRP::Pipeline("StandardRP.Pipeline");

		mainDevice = Rendering::IAPI::GetInstance()->GetDevice();

		return IApplicationComponent::Init();
	}

	void ApplicationRenderingSystem::Release() {

		if (mainPipeline != 0) {

			mainPipeline->Release();

		}

		IApplicationComponent::Release();

	}



	/**
	 *	Properties
	 */
	void	ApplicationRenderingSystem::SetMainPipeline(Rendering::C_Pipeline* pipeline) {

		this->mainPipeline = pipeline;

	}
		
	void	ApplicationRenderingSystem::ReleaseMainPipeline() {

		if (mainPipeline != 0) {

			mainPipeline->Release();

			mainPipeline = 0;

		}

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

		//pipeline->Render(device->GetImmediateContext());

	}

	void	ApplicationRenderingSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}

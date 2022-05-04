
/**
 *	Include Header
 */
#include "UISystem.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



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
 *	Include UI Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



/**
 *	Include UI Canvas
 */
#include <ING/UI/Canvas/Canvas.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationUISystem::ApplicationUISystem(IApplication* application) :
		IApplicationComponent(application, "UISystem"),

		mainCanvas(0)
	{



	}

	ApplicationUISystem::~ApplicationUISystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationUISystem::Init() {

		mainCanvas = new UI::ICanvas();

		return IApplicationComponent::Init();
	}

	void ApplicationUISystem::Release() {

		if (mainCanvas != 0) {

			mainCanvas->Release();

		}

		IApplicationComponent::Release();

	}



	/**
	 *	Properties
	 */
	void	ApplicationUISystem::ReleaseMainCanvas() {

		if (this->mainCanvas != 0) {

			this->mainCanvas->Release();

		}

	}

	void	ApplicationUISystem::SetMainCanvas(UI::ICanvas* mainCanvas) {

		this->mainCanvas = mainCanvas;

	}



	/**
	 *	Methods
	 */
	void	ApplicationUISystem::Start() {

		IApplicationComponent::Start();

		mainCanvas->Start();

	}

	void	ApplicationUISystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

		mainCanvas->PreUpdate();

	}

	void	ApplicationUISystem::Update() {

		IApplicationComponent::Update();

		mainCanvas->Update();

	}

	void	ApplicationUISystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

		mainCanvas->LateUpdate();

	}

	void	ApplicationUISystem::PreRender() {

		IApplicationComponent::PreRender();

		mainCanvas->PreRender();

	}

	void	ApplicationUISystem::Render() {

		IApplicationComponent::Render();

		mainCanvas->Render();

	}

	void	ApplicationUISystem::LateRender() {

		IApplicationComponent::LateRender();

		mainCanvas->LateRender();

	}

}

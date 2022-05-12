
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
		IApplicationComponent(application, "UISystem")
	{



	}

	ApplicationUISystem::~ApplicationUISystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationUISystem::Init() {



		return IApplicationComponent::Init();
	}

	void ApplicationUISystem::Release() {

		for (auto item = name2CanvasMap.begin(); item != name2CanvasMap.end();) {

			(item++)->second->Release();

		}

		IApplicationComponent::Release();

	}



	/**
	 *	Methods
	 */
	void	ApplicationUISystem::AddCanvas(UI::Canvas* canvas) {

		name2CanvasMap[canvas->GetName()] = canvas;

	}

	void	ApplicationUISystem::RemoveCanvas(UI::Canvas* canvas) {

		name2CanvasMap.erase(canvas->GetName());

	}

	void	ApplicationUISystem::Start() {

		IApplicationComponent::Start();

		for (auto item : name2CanvasMap) {

			item.second->Start();

		}

	}

	void	ApplicationUISystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

		for (auto item : name2CanvasMap) {

			item.second->PreUpdate();

		}

	}

	void	ApplicationUISystem::Update() {

		IApplicationComponent::Update();

		for (auto item : name2CanvasMap) {

			item.second->Update();

		}

	}

	void	ApplicationUISystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

		for (auto item : name2CanvasMap) {

			item.second->LateUpdate();

		}

	}

	void	ApplicationUISystem::PreRender() {

		IApplicationComponent::PreRender();

		for (auto item : name2CanvasMap) {

			item.second->PreRender();

		}

	}

	void	ApplicationUISystem::Render() {

		IApplicationComponent::Render();

		for (auto item : name2CanvasMap) {

			item.second->Render();

		}

	}

	void	ApplicationUISystem::LateRender() {

		IApplicationComponent::LateRender();

		for (auto item : name2CanvasMap) {

			item.second->LateRender();

		}

	}

}

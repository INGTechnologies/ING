
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



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Reflection System
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationUISystem::ApplicationUISystem(IApplication* application) :
		IApplicationComponent(application, "UISystem")
	{

		IApplicationModule* module = new IApplicationModule("ING.UI");

		module->RegisterType<UI::C_Element>(0);
		module->RegisterType<UI::C_Canvas>(0);

		GetApplication()->AddModule(module);

		GetApplication()->GetModule("ING")->AddDependency("ING.UI");

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
	void	ApplicationUISystem::AddCanvas(UI::C_Canvas* canvas) {

		if (name2CanvasMap.find(canvas->GetName()) != name2CanvasMap.end()) return;

		name2CanvasMap[canvas->GetName()] = canvas;

	}

	void	ApplicationUISystem::RemoveCanvas(UI::C_Canvas* canvas) {

		if (name2CanvasMap.find(canvas->GetName()) == name2CanvasMap.end()) return;

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

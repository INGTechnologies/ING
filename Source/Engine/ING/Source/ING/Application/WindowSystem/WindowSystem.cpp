
/**
 *	Include Header
 */
#include "WindowSystem.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationWindowSystem::ApplicationWindowSystem(IApplication* application) :
		IApplicationComponent(application, "WindowSystem")
	{



	}

	ApplicationWindowSystem::~ApplicationWindowSystem()
	{



	}



	/**
	 *	Release Methods
	 */
	bool ApplicationWindowSystem::Init()
	{

		return IApplicationComponent::Init();

	}

	void ApplicationWindowSystem::Release()
	{

		IApplicationComponent::Release();

	}



	/**
	 *	Methods
	 */
	void	ApplicationWindowSystem::AddWindow		(IWindow* window) {

		name2WindowMap[window->GetName()] = window;

	}

	void	ApplicationWindowSystem::RemoveWindow		(IWindow* window) {

		name2WindowMap.erase(window->GetName());

	}

	void	ApplicationWindowSystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationWindowSystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationWindowSystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationWindowSystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationWindowSystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationWindowSystem::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationWindowSystem::LateRender() {

		IApplicationComponent::LateRender();

	}
	
}
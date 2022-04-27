
/**
 *	Include Header
 */
#include "Manager.h"



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
	ApplicationWindowManager::ApplicationWindowManager(IApplication* application) :
		IApplicationComponent(application, "WindowManager")
	{



	}

	ApplicationWindowManager::~ApplicationWindowManager()
	{



	}



	/**
	 *	Release Methods
	 */
	bool ApplicationWindowManager::Init()
	{

		return IApplicationComponent::Init();

	}

	void ApplicationWindowManager::Release()
	{

		IApplicationComponent::Release();

	}



	/**
	 *	Methods
	 */
	void	ApplicationWindowManager::AddWindow		(IWindow* window) {

		name2WindowMap[window->GetName()] = window;

	}

	void	ApplicationWindowManager::RemoveWindow		(IWindow* window) {

		name2WindowMap.erase(window->GetName());

	}

	void	ApplicationWindowManager::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationWindowManager::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationWindowManager::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationWindowManager::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationWindowManager::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationWindowManager::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationWindowManager::LateRender() {

		IApplicationComponent::LateRender();

	}
	
}

/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Run Event
 */
#include <ING/Application/Event/Run/Run.h>



/**
 *	Include Shutdown Event
 */
#include <ING/Application/Event/Shutdown/Shutdown.h>



/**
 *	Include Start Frame Update Event
 */
#include <ING/Application/Event/FrameUpdate/Start.h>



/**
 *	Include Frame Update Event
 */
#include <ING/Application/Event/FrameUpdate/FrameUpdate.h>



/**
 *	Include End Frame Update Event
 */
#include <ING/Application/Event/FrameUpdate/End.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationEventManager::ApplicationEventManager() {

		Debug::Log("Start Creating ApplicationEventManager");

		Debug::Log("ApplicationEventManager Created");

	}

	ApplicationEventManager::~ApplicationEventManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationEventManager::Init() {

		Debug::Log("Start Initializing ApplicationEventManager");

		/**
		 *	Add Events
		 */
		/* Run Event */
		Application::GetInstance()->AddEvent( new ApplicationRunEvent());

		/* Shutdown Event */
		Application::GetInstance()->AddEvent( new ApplicationShutdownEvent());

		/* Start Frame Update Event */
		Application::GetInstance()->AddEvent( new ApplicationStartFrameUpdateEvent());

		/* Frame Update Event */
		Application::GetInstance()->AddEvent(new ApplicationFrameUpdateEvent());

		/* End Frame Update Event */
		Application::GetInstance()->AddEvent( new ApplicationEndFrameUpdateEvent());

		Debug::Log("ApplicationEventManager Initialized");

		return Square::Init();
	}

	bool ApplicationEventManager::Run() {

		Debug::Log("Start Running ApplicationEventManager");

		return Square::Run();
	}

	bool ApplicationEventManager::Release() {

		Debug::Log("Start Releasing ApplicationEventManager");

		Debug::Log("Finished Releasing ApplicationEventManager");

		return Square::Release();
	}

}
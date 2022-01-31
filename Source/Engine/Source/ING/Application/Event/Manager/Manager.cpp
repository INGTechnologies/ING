
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
 *	Include Frame Update Event
 */
#include <ING/Application/Event/FrameUpdate/Start.h>



/**
 *	Include End Frame Update Event
 */
#include <ING/Application/Event/FrameUpdate/End.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationEventManager::ApplicationEventManager() {



	}

	ApplicationEventManager::~ApplicationEventManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationEventManager::Init() {

		/**
		 *	Add Events
		 */
		/* Run Event */
		Application::GetInstance()->AddEvent( new ApplicationRunEvent());

		/* Shutdown Event */
		Application::GetInstance()->AddEvent( new ApplicationShutdownEvent());

		/* Frame Update Event */
		Application::GetInstance()->AddEvent( new ApplicationStartFrameUpdateEvent());

		/* End Frame Update Event */
		Application::GetInstance()->AddEvent( new ApplicationEndFrameUpdateEvent());

		return Square::Init();
	}

	bool ApplicationEventManager::Run() {



		return Square::Run();
	}

	bool ApplicationEventManager::Release() {



		return Square::Release();
	}

}
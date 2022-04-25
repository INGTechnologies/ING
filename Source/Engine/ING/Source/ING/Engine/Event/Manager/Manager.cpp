
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Run Event
 */
#include <ING/Engine/Event/Run/Run.h>



/**
 *	Include Shutdown Event
 */
#include <ING/Engine/Event/Shutdown/Shutdown.h>



/**
 *	Include Start Frame Update Event
 */
#include <ING/Engine/Event/FrameUpdate/Start.h>



/**
 *	Include Frame Update Event
 */
#include <ING/Engine/Event/FrameUpdate/FrameUpdate.h>



/**
 *	Include End Frame Update Event
 */
#include <ING/Engine/Event/FrameUpdate/End.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EngineEventManager::EngineEventManager() {

		Debug::Log("Start Creating EngineEventManager");

		Debug::Log("EngineEventManager Created");

	}

	EngineEventManager::~EngineEventManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool EngineEventManager::Init() {

		Debug::Log("Start Initializing EngineEventManager");

		/**
		 *	Add Events
		 */
		/* Run Event */
		Engine::GetInstance()->AddEvent( new EngineRunEvent());

		/* Shutdown Event */
		Engine::GetInstance()->AddEvent( new EngineShutdownEvent());

		/* Start Frame Update Event */
		Engine::GetInstance()->AddEvent( new EngineStartFrameUpdateEvent());

		/* Frame Update Event */
		Engine::GetInstance()->AddEvent(new EngineFrameUpdateEvent());

		/* End Frame Update Event */
		Engine::GetInstance()->AddEvent( new EngineEndFrameUpdateEvent());

		Debug::Log("EngineEventManager Initialized");

		return Square::Init();
	}

	bool EngineEventManager::Run() {

		Debug::Log("Start Running EngineEventManager");

		return Square::Run();
	}

	bool EngineEventManager::Release() {

		Debug::Log("Start Releasing EngineEventManager");

		Debug::Log("Finished Releasing EngineEventManager");

		return Square::Release();
	}

}

/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EventManager::EventManager() {

		Debug::Log("Start Creating EventManager");

		Debug::Log("EventManager Created");

	}

	EventManager::~EventManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool EventManager::Init() {

		Debug::Log("Start Initializing EventManager");

		Debug::Log("EventManager Initialized");

		return Square::Init();
	}

	bool EventManager::Run() {

		Debug::Log("Start Running EventManager");

		return Square::Run();
	}

	bool EventManager::Release() {

		Debug::Log("Start Releasing EventManager");

		Debug::Log("Finished Releasing EventManager");

		return Square::Release();
	}


}
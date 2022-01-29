
/**
 *	Include Header
 */
#include "EventManager.h"



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



		return Square::Init();
	}

	bool ApplicationEventManager::Run() {



		return Square::Run();
	}

	bool ApplicationEventManager::Release() {



		return Square::Release();
	}

}
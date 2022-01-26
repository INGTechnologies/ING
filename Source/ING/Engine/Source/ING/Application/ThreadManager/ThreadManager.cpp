
/**
 *	Include Header
 */
#include "ThreadManager.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationThreadManager::ApplicationThreadManager() {



	}

	ApplicationThreadManager::~ApplicationThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationThreadManager::Init() {



		return Square::Init();
	}

	bool ApplicationThreadManager::Run() {



		return Square::Run();
	}

	bool ApplicationThreadManager::Release() {



		return Square::Release();
	}

}

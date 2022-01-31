
/**
 *	Include Header
 */
#include "ThreadManager.h"



/**
 *	Include Application
 */
#include "ING/Application/Application.h"



/**
 *	Include Event
 */
#include "ING/Event/Event.h"



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

		/* Add Event Listeners */
		Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {
			
			ApplicationThreadManager::GetInstance()->StartFrame();
			
		});

		Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {

			ApplicationThreadManager::GetInstance()->EndFrame();

		});

		return Square::Init();
	}

	bool ApplicationThreadManager::Run() {



		return Square::Run();
	}

	bool ApplicationThreadManager::Release() {



		return Square::Release();
	}



	/**
	 *	StartFrame, EndFrame Method
	 */
	void ApplicationThreadManager::StartFrame() {



	}

	void ApplicationThreadManager::EndFrame() {



	}


}

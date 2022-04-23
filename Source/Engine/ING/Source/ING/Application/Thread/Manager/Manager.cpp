
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Thread
 */
#include <ING/Thread/Thread.h>



/**
 *	Include Rendering Thread
 */
#include <ING/Application/Thread/Rendering/Rendering.h>



/**
 *	Include Physics Thread
 */
#include <ING/Application/Thread/Physics/Physics.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationThreadManager::ApplicationThreadManager() :
		renderingThread(0),
		physicsThread(0)
	{

		Debug::Log("Start Creating ApplicationThreadManager");

		APPLICATION_CONFIG_PROP(bool, "ING.ApplicationThreadManager.usePhysicsThread", true);

		APPLICATION_CONFIG_PROP(bool, "ING.ApplicationThreadManager.useRenderingThread", true);

		Debug::Log("ApplicationThreadManager Created");

	}

	ApplicationThreadManager::~ApplicationThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationThreadManager::Init() {

		Debug::Log("Start Initializing ApplicationThreadManager");

		/**
		 *	Create Threads
		 */
		/* Rendering Thread */
		renderingThread = new ApplicationRenderingThread();
		applicationThreadList.Add(renderingThread);
		
		/* Physics Thread */
		physicsThread = new ApplicationPhysicsThread();
		applicationThreadList.Add(physicsThread);



		/**
		 *	Add Event Listeners
		 */
		//Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {
			
		//	ApplicationThreadManager::GetInstance()->StartFrame();
			
		//});

		//Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {

		//	ApplicationThreadManager::GetInstance()->EndFrame();

		//});

		Debug::Log("ApplicationThreadManager Initialized");

		return Square::Init();
	}

	bool ApplicationThreadManager::Run() {

		Debug::Log("Start Running ApplicationThreadManager");

		/**
		 *	Start Threads
		 */
		applicationThreadList.Foreach([](ApplicationThread*& thread) {

			thread->Start();

		});



		return Square::Run();
	}

	bool ApplicationThreadManager::Release() {

		Debug::Log("Start Releasing ApplicationThreadManager");

		applicationThreadList.Foreach([](ApplicationThread*& thread) {

			thread->Join();

		});

		applicationThreadList.Clear();

		Debug::Log("Finished Releasing ApplicationThreadManager");

		return Square::Release();
	}



	/**
	 *	StartFrame, EndFrame Method
	 */
	void ApplicationThreadManager::StartFrame() {

		applicationThreadList.Foreach([](ApplicationThread*& thread) {
		
			thread->StartUpdate();
			
		});

	}

	void ApplicationThreadManager::EndFrame() {

		applicationThreadList.Foreach([](ApplicationThread*& thread) {
		
			thread->WaitUpdate();
			
		});

	}

}

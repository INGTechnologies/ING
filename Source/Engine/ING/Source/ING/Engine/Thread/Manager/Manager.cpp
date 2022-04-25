
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



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
#include <ING/Engine/Thread/Rendering/Rendering.h>



/**
 *	Include Physics Thread
 */
#include <ING/Engine/Thread/Physics/Physics.h>



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
	EngineThreadManager::EngineThreadManager() :
		renderingThread(0),
		physicsThread(0)
	{

		Debug::Log("Start Creating EngineThreadManager");

		ING_ENGINE_CONFIG_PROP(bool, "ING.EngineThreadManager.usePhysicsThread", true);

		ING_ENGINE_CONFIG_PROP(bool, "ING.EngineThreadManager.useRenderingThread", true);

		Debug::Log("EngineThreadManager Created");

	}

	EngineThreadManager::~EngineThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool EngineThreadManager::Init() {

		Debug::Log("Start Initializing EngineThreadManager");

		/**
		 *	Create Threads
		 */
		/* Rendering Thread */
		renderingThread = new EngineRenderingThread();
		applicationThreadList.Add(renderingThread);
		
		/* Physics Thread */
		physicsThread = new EnginePhysicsThread();
		applicationThreadList.Add(physicsThread);



		/**
		 *	Add Event Listeners
		 */
		//Engine::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {
			
		//	EngineThreadManager::GetInstance()->StartFrame();
			
		//});

		//Engine::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {

		//	EngineThreadManager::GetInstance()->EndFrame();

		//});

		Debug::Log("EngineThreadManager Initialized");

		return Square::Init();
	}

	bool EngineThreadManager::Run() {

		Debug::Log("Start Running EngineThreadManager");

		/**
		 *	Start Threads
		 */
		applicationThreadList.Foreach([](EngineThread*& thread) {

			thread->Start();

		});



		return Square::Run();
	}

	bool EngineThreadManager::Release() {

		Debug::Log("Start Releasing EngineThreadManager");

		applicationThreadList.Foreach([](EngineThread*& thread) {

			thread->Join();

		});

		applicationThreadList.Clear();

		Debug::Log("Finished Releasing EngineThreadManager");

		return Square::Release();
	}



	/**
	 *	StartFrame, EndFrame Method
	 */
	void EngineThreadManager::StartFrame() {

		applicationThreadList.Foreach([](EngineThread*& thread) {
		
			thread->StartUpdate();
			
		});

	}

	void EngineThreadManager::EndFrame() {

		applicationThreadList.Foreach([](EngineThread*& thread) {
		
			thread->WaitUpdate();
			
		});

	}

}


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



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationThreadManager::ApplicationThreadManager() {

		APPLICATION_CONFIG_PROP(bool, "ING::ApplicationThreadManager::usePhysicsThread", true);

		APPLICATION_CONFIG_PROP(bool, "ING::ApplicationThreadManager::useRenderingThread", true);

	}

	ApplicationThreadManager::~ApplicationThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationThreadManager::Init() {

		/**
		 *	Create Threads
		 */
		/* Rendering Thread */
		renderingThread = new ApplicationRenderingThread();
		
		/* Physics Thread */
		physicsThread = new ApplicationPhysicsThread();



		/**
		 *	Add Event Listeners
		 */
		Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {
			
			ApplicationThreadManager::GetInstance()->StartFrame();
			
		});

		Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {

			ApplicationThreadManager::GetInstance()->EndFrame();

		});

		return Square::Init();
	}

	bool ApplicationThreadManager::Run() {

		/**
		 *	Start Threads
		 */
		applicationThreadList.Foreach([](ApplicationThread*& thread) {

			thread->Start();

		});



		return Square::Run();
	}

	bool ApplicationThreadManager::Release() {

		applicationThreadList.Foreach([](ApplicationThread*& thread) {

			thread->Join();

		});

		applicationThreadList.Clear();

		Debug::Log("ApplicationThreadManager::Release");

		return Square::Release();
	}



	/**
	 *	Thread Management
	 */
	List<ApplicationThread*>::Node*		ApplicationThreadManager::AddThread(ApplicationThread* thread) {

		return applicationThreadList.Add(thread);

	}

	void								ApplicationThreadManager::RemoveThread(List<ApplicationThread*>::Node* node) {

		applicationThreadList.Remove(node);

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

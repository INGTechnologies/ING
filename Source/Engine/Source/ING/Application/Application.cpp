
/**
 *	Include Header
 */
#include "Application.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Core
 */
#include <ING/Core/Core.h>



 /**
  *	Include Thread Managers
  */
#include <ING/Thread/Manager/Manager.h>

#include <ING/Application/Thread/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Event Managers
 */
#include <ING/Event/Manager/Manager.h>

#include <ING/Application/Event/Manager/Manager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include JobSystem
 */
#include <ING/Job/System/System.h>



/**
 *	Include ApplicationConfiguration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Window Manager
 */
#include <ING/Window/Manager/Manager.h>



/**
 *	Include Resource Manager
 */
#include <ING/Resource/Manager/Manager.h>



/**
 *	Include Time
 */
#include <ING/Time/Time.h>



/**
 *	Include Camera Manager
 */
#include <ING/Camera/Manager/Manager.h>



/**
 *	Include Screen Manager
 */
#include <ING/Screen/Manager/Manager.h>



/**
 *	Include System
 */
#include <ING/System/System.h>



/**
 *	Include ECS Repository Manager
 */
#include <ING/ECS/Core/Repository/Manager/Manager.h>



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Application::Application() :
		configuration(0)
	{

		state = NONE_APPLICATION_STATE;



		Debug::Log("Start Creating Application");



		/**
		 *	Create Configuration
		 */
		configuration = new Configuration();



		/**
		 *	Load Configuration
		 */
		LoadConfiguration();



		/**
		 *	Add Squares
		 */
		/* System */
		AddSquare<System>();

		/* Core */
		AddSquare<Core>();

		/* Time */
		AddSquare<Time>();

		/* Profiler */
		AddSquare<Profiler>();

		/* Resource Manager */
		AddSquare<ResourceManager>();

		/* Event Managers */
		AddSquare<EventManager>();

		/* Application Event Managers */
		AddSquare<ApplicationEventManager>();

		/* Thread Managers */
		AddSquare<ThreadManager>();

		/* Application Thread Managers */
		AddSquare<ApplicationThreadManager>();

		/* Rendering Engine */
		AddSquare<Rendering::Engine>();

		/* Screen Manager */
		AddSquare<ScreenManager>();

		/* Window Manager */
		AddSquare<WindowManager>();

		/* Job System */
		AddSquare<JobSystem>();

		/* Resource Manager */
		AddSquare<CameraManager>();

		/* ECS Repository Manager */
		AddSquare<ECS::RepositoryManager>();



		state = CREATED_APPLICATION_STATE;



		Debug::Log("Application Created");

	}

	Application::~Application() {

		

	}



	/**
	 *	Configuration 
	 */
	void Application::LoadConfiguration() {



	}



	/**
	 *	Init, Run, Release, Shutdown Methods
	 */
	bool Application::Init() {

		Debug::Log("Start Initializing Application");

		bool result = Board<Application>::Init();

		Debug::Log("Application Initialized");

		return result;
	}

	bool Application::Run() {

		state = RUNNING_APPLICATION_STATE;

		Debug::Log("Start Running Application");

		bool squaresRunResult = Board<Application>::Run();

		Debug::Log(String("Start ") + String('"') + String("RUN") + String('"') + String(" Event"));

		GetEvent("RUN")->Execute();

		Debug::Log("Start Gameloop");

		/* Game Loop */
		while (state == RUNNING_APPLICATION_STATE) {

			/* Check For Shutting Down */
			unsigned int windowCount = WindowManager::GetInstance()->GetWindowMap().size();

			if (WindowManager::GetInstance()->IsAutoShutdown() && windowCount == 1) {

				Application::GetInstance()->Shutdown();

				break;

			}



			/* Check Message */
			if (!WindowManager::GetInstance()->CheckMessage()) {

				FrameUpdate();

			}

		}

		return squaresRunResult;
	}

	bool Application::Release() {

		Debug::Log("Start Releasing Application");

		delete configuration;

		RELEASE_EVENT_STORAGE();

		bool result = Board<Application>::Release();
	
		if(result)
			Debug::Log("Finished Releasing Application");
		else {

			Debug::Log("Cant Release Application");

		}

		return result;
	}

	void Application::Shutdown() {

		state = CLOSED_APPLICATION_STATE;

		Debug::Log("Start Shuting Down Application");

		Release();

		Debug::Log("Finished Shutting Application");
	}



	/**
	 *	FrameUpdate Method
	 */
	void Application::FrameUpdate() {

		Time::GetInstance()->StartFrame();



		CameraManager::GetInstance()->FrameUpdate();



		ECS::RepositoryManager::GetInstance()->PreUpdate();


		GetEvent("START_FRAME_UPDATE")->Execute();

		ApplicationThreadManager::GetInstance()->StartFrame();

		if (!configuration->Get<bool>("ING::ApplicationThreadManager::usePhysicsThread")) {



		}



		ECS::RepositoryManager::GetInstance()->Update();



		if (!configuration->Get<bool>("ING::ApplicationThreadManager::useRenderingThread")) {

			Rendering::Engine::GetInstance()->FrameUpdate();

		}

		ApplicationThreadManager::GetInstance()->EndFrame();

		GetEvent("END_FRAME_UPDATE")->Execute();

		Time::GetInstance()->EndFrame();

	}

}

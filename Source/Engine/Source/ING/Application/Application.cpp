
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
 *	Include System
 */
#include <ING/System/System.h>



/**
 *	Include ECS Repository Manager
 */
#include <ING/ECS/Repository/Manager/Manager.h>



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Application::Application() {

		state = NONE_APPLICATION_STATE;



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

		AddSquare<ApplicationEventManager>();

		/* Thread Managers */
		AddSquare<ThreadManager>();

		AddSquare<ApplicationThreadManager>();

		/* Rendering Engine */
		AddSquare<Rendering::Engine>();

		/* Window Manager */
		AddSquare<WindowManager>();

		/* Job System */
		AddSquare<JobSystem>();

		/* Resource Manager */
		AddSquare<CameraManager>();

		/* ECS Repository Manager */
		AddSquare<ECS::RepositoryManager>();



		state = CREATED_APPLICATION_STATE;

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



		return Board<Application>::Init();
	}

	bool Application::Run() {

		state = RUNNING_APPLICATION_STATE;

		bool squaresRunResult = Board<Application>::Run();

		GetEvent("RUN")->Execute();

		/* Game Loop */
		while (state == RUNNING_APPLICATION_STATE) {

			/* Check Message */
			if (!WindowManager::GetInstance()->CheckMessage()) {

				FrameUpdate();

			}



			/* Check For Shutting Down */
			unsigned int windowCount = WindowManager::GetInstance()->GetWindowMap().size();

			if (WindowManager::GetInstance()->IsAutoShutdown() && windowCount == 1) {

				Application::GetInstance()->Shutdown();

				break;

			}

		}

		return squaresRunResult;
	}

	bool Application::Release() {

		delete configuration;

		RELEASE_EVENT_STORAGE();

		return Board<Application>::Release();
	}

	void Application::Shutdown() {

		state = CLOSED_APPLICATION_STATE;

		Release();

	}



	/**
	 *	FrameUpdate Method
	 */
	void Application::FrameUpdate() {

		Time::GetInstance()->StartFrame();

		GetEvent("START_FRAME_UPDATE")->Execute();

		if (!configuration->Get<bool>("ING::ApplicationThreadManager::usePhysicsThread")) {



		}



		/* Update Repositories */
		ECS::RepositoryManager::GetInstance()->Update();



		if (!configuration->Get<bool>("ING::ApplicationThreadManager::useRenderingThread")) {

			Rendering::Engine::GetInstance()->FrameUpdate();

		}

		GetEvent("END_FRAME_UPDATE")->Execute();

		Time::GetInstance()->EndFrame();

	}

}


/**
 *	Include Header
 */
#include "Engine.h"



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

#include <ING/Engine/Thread/Manager/Manager.h>



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

#include <ING/Engine/Event/Manager/Manager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include JobSystem
 */
#include <ING/Job/System/System.h>



/**
 *	Include EngineConfiguration
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
#include <ING/ECS/Repository/Manager/Manager.h>



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h>



/**
 *	Include Scripting Manager
 */
#include <ING/Scripting/Manager/Manager.h>



/**
 *	Include Object Manager
 */
#include <ING/Object/Manager/Manager.h>



#include <filesystem>



/**
 *	Include ApplicationManager
 */
#include <ING/Application/Manager/Manager.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Engine::Engine() :
		configuration(0)
	{

		state = NONE_APPLICATION_STATE;



		Debug::Log("Start Creating Engine");



		/**
		 *	Create Configuration And ConfigurationCompiler
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

		/* Engine Event Managers */
		AddSquare<EngineEventManager>();

		/* Thread Managers */
		AddSquare<ThreadManager>();

		/* Engine Thread Managers */
		AddSquare<EngineThreadManager>();

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

		/* Object Manager */
		AddSquare<ObjectManager>();

		/* Scripting Manager */
		AddSquare<Scripting::Manager>();

		/* ECS Repository Manager */
		AddSquare<ECS::RepositoryManager>();

		/* Application Manager */
		AddSquare<ApplicationManager>();



		state = CREATED_APPLICATION_STATE;



		ING_ENGINE_CONFIG_PROP(unsigned int, "ING.Engine.terminationBehavior", 0);

		ING_ENGINE_CONFIG_PROP(std::string, "ING.Engine.gameDir", "../Game/");
		ING_ENGINE_CONFIG_PROP(std::string, "ING.Engine.workingDir", ".");

		ING_ENGINE_CONFIG_PROP(std::string, "ING.Engine.name", "ING App");

		Debug::Log("Engine Created");

	}

	Engine::~Engine() {

		

	}



	/**
	 *	Configuration 
	 */
	void Engine::LoadConfiguration() { 

		configuration->LoadFromFile("./Config.ini");

	}



	/**
	 *	Init, Run, Release, Shutdown Methods
	 */
	bool Engine::Init() {  

		Debug::Log("Start Initializing Engine");

		AddRootPath(L"CWD", std::filesystem::current_path().wstring() + WString(L"/"));
		AddRootPath(L"CWD/../", std::filesystem::current_path().wstring() + WString(L"/../"));

		gameDir_wstr = Path::GetAbsolutePath(WString(configuration->Get<std::string>("ING.Engine.gameDir")));
		gameDir = String(gameDir_wstr);
		workingDir_wstr = Path::GetAbsolutePath(WString(configuration->Get<std::string>("ING.Engine.workingDir")));
		workingDir = String(workingDir_wstr);

		AddRootPath(L"Game", gameDir_wstr);
		AddRootPath(L"Engine", workingDir_wstr);

		name = configuration->Get<std::string>("ING.Engine.name");

		bool result = Board<Engine>::Init(); 

		if (!result) {

			Debug::Error("Cant Initialize Engine");

			unsigned int terminationBehavior = configuration->Get<unsigned int>("ING.Engine.terminationBehavior");

			if (terminationBehavior == 1) {
				system("pause");
			}
			 
			exit(1);

		}
		else {

			Debug::Log("Engine Initialized");

		}

		return result;
	}

	bool Engine::Run() {

		state = RUNNING_APPLICATION_STATE;

		Debug::Log("Start Running Engine");

		bool squaresRunResult = Board<Engine>::Run();

		if (!squaresRunResult) {

			Debug::Error("Cant Run Engine");

			Engine::GetInstance()->Shutdown();

			exit(1);

		}

		Debug::Log(String("Start ") + String('"') + String("RUN") + String('"') + String(" Event"));

		ApplicationManager::GetInstance()->Start();

		GetEvent("RUN")->Execute();

		Debug::Log("Start Gameloop");

		/* Game Loop */
		while (state == RUNNING_APPLICATION_STATE) {

			/* Check For Shutting Down */
			//unsigned int windowCount = WindowManager::GetInstance()->GetWindowMap().size();

			//if (WindowManager::GetInstance()->IsAutoShutdown() && windowCount == 1) {

			//	Engine::GetInstance()->Shutdown();

			//	break;

			//}



			/* Check Message */
			if (!WindowManager::GetInstance()->CheckMessage()) {

				FrameUpdate();

			}

		}

		return squaresRunResult;
	}

	bool Engine::Release() {

		Debug::Log("Start Releasing Engine");

		delete configuration;

		RELEASE_EVENT_STORAGE();

		bool result = Board<Engine>::Release();
	
		if(result)
			Debug::Log("Finished Releasing Engine");
		else {

			Debug::Error("Cant Release Engine");

		}

		return result;
	}

	void Engine::Shutdown() {

		state = CLOSED_APPLICATION_STATE; 

		Debug::Log("Start Shuting Down Engine");

		unsigned int terminationBehavior = configuration->Get<unsigned int>("ING.Engine.terminationBehavior");

		Release();

		Debug::Log("Finished Shutting Engine");

		if(terminationBehavior == 1) {
			system("pause");
		}

		exit(0);
	}



	/**
	 *	Methods
	 */
	void Engine::FrameUpdate() {

		Time::GetInstance()->StartFrame();



		ApplicationManager::GetInstance()->PreUpdate();

		CameraManager::GetInstance()->FrameUpdate();



		ECS::RepositoryManager::GetInstance()->PreUpdate();


		GetEvent("START_FRAME_UPDATE")->Execute();

		EngineThreadManager::GetInstance()->StartFrame();

		if (!configuration->Get<bool>("ING.EngineThreadManager.usePhysicsThread")) {



		}

		ApplicationManager::GetInstance()->Update();

		ECS::RepositoryManager::GetInstance()->Update();
		ECS::RepositoryManager::GetInstance()->LateUpdate();

		ApplicationManager::GetInstance()->LateUpdate();



		if (!configuration->Get<bool>("ING.EngineThreadManager.useRenderingThread")) {

			Rendering::Engine::GetInstance()->FrameUpdate();

		}

		EngineThreadManager::GetInstance()->EndFrame();

		GetEvent("END_FRAME_UPDATE")->Execute();

		Time::GetInstance()->EndFrame();

	}

	void Engine::AddRootPath(const std::wstring& path, const std::wstring& value) {

		rootPath2AbsolutePath[path] = value;

	}

}

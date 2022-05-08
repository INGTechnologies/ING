
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



/**
 *	Include UI Engine
 */
#include <ING/UI/Engine/Engine.h>



/**
 *	Include Reflection Engine
 */
#include <ING/Reflection/Engine/Engine.h>



/**
 *	Include PluginManager
 */
#include <ING/Plugin/Manager/Manager.h>



#include <nlohmann/json.hpp>



/**
 *	Include GameFramework
 */
#include <ING/GameFramework/GameFramework.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Engine::Engine() :
		Board<Engine>(),

		configuration(0)
	{

		state = NONE_APPLICATION_STATE;



		Debug::Log("Start Creating Engine");







		/**
		 *	Create Configuration And ConfigurationCompiler
		 */
		configuration = new Configuration();

		configuration->LoadFromFile(L"./Config.ini");



		/**
		 *	Add Squares
		 */
		 /* Plugin Manager */
		AddSquare<PluginManager>();

		/* System */
		AddSquare<System>();

		/* Core */
		AddSquare<Core>();

		/* Reflection Engine */
		AddSquare<Reflection::Engine>();

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

		AddSquare<UI::Engine>();

		/* ECS Repository Manager */
		AddSquare<ECS::RepositoryManager>();

		/* GameFramework */
		AddSquare<GameFramework>();

		/* Application Manager */
		AddSquare<ApplicationManager>();



		state = CREATED_APPLICATION_STATE;



		ING_ENGINE_CONFIG_PROP(unsigned int, "ING.Engine.terminationBehavior", 0);

		ING_ENGINE_CONFIG_PROP(String, "ING.Engine.gameDir", "../Game/");
		ING_ENGINE_CONFIG_PROP(String, "ING.Engine.workingDir", ".");

		ING_ENGINE_CONFIG_PROP(String, "ING.Engine.name", "ING App");

		ING_ENGINE_CONFIG_PROP(String, "ING.Engine.mode", "ING.Standalone");

		SetRootPath(L"CWD", std::filesystem::current_path().wstring() + WString(L"/"));
		SetRootPath(L"CWD/../", std::filesystem::current_path().wstring() + WString(L"/../"));

		gameDir = Path::GetAbsolutePath(ToWString(configuration->Get<String>("ING.Engine.gameDir")));
		workingDir = Path::GetAbsolutePath(ToWString(configuration->Get<String>("ING.Engine.workingDir")));

		mode = configuration->Get<String>("ING.Engine.mode");

		SetRootPath(L"Game", gameDir);
		SetRootPath(L"Engine", workingDir);



		if (!PluginManager::GetInstance()->LoadPlugins(L"Engine:/Plugins/")) {

			Debug::Error("Plugin Cant Load Plugins In Engine:/Plugins/");

			Shutdown();

			return;

		}

		if (!PluginManager::GetInstance()->LoadPlugins(L"Game:/Plugins/")) {

			Debug::Error("Plugin Cant Load Plugins In Game:/Plugins/");

			Shutdown();

			return;

		}



		if (!PluginManager::GetInstance()->LateCreate()) {

			Debug::Error("Plugin LateCreate Error");

			Shutdown();

			return;

		}

		Debug::Log("Engine Created");

	}

	Engine::Engine(const std::vector<WString>& argv) : 
		Engine()
	{

		this->argv = argv;

	}

	Engine::~Engine() {

		

	}



	/**
	 *	Init, Run, Release, Shutdown Methods
	 */
	bool Engine::Init() {  

		Debug::Log("Start Initializing Engine");

		name = configuration->Get<String>("ING.Engine.name");

		if (!PluginManager::GetInstance()->PreInit()) {

			Debug::Error("Plugin PreInit Error");

			Shutdown();

			return false;

		}

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

		if (!PluginManager::GetInstance()->LateInit()) {

			Debug::Error("Plugin LateInit Error");

			Shutdown();

			return false;

		}

		return result;
	}

	bool Engine::Run() {

		state = RUNNING_APPLICATION_STATE;

		Debug::Log("Start Running Engine");		
		
		if (!PluginManager::GetInstance()->PreRun()) {

			Debug::Error("Plugin PreRun Error");

			Shutdown();

			return false;

		}

		bool squaresRunResult = Board<Engine>::Run();

		if (!squaresRunResult) {

			Debug::Error("Cant Run Engine");

			Engine::GetInstance()->Shutdown();

			exit(1);

		}

		Debug::Log(ToString("Start ") + ToString('"') + ToString("RUN") + ToString('"') + ToString(" Event"));

		ApplicationManager::GetInstance()->Start();

		GetEvent("RUN")->Execute();

		Debug::Log("Start Gameloop");

		/* Game Loop */
		while (state == RUNNING_APPLICATION_STATE) {

			/* Check Message */
			if (!WindowManager::GetInstance()->CheckMessage()) {

				FrameUpdate();

			}

		}

		return squaresRunResult;
	}

	bool Engine::Release() {

		Debug::Log("Start Releasing Engine");

		if (!PluginManager::GetInstance()->PreRelease()) {

			Debug::Error("Plugin PreRelease Error");

			if (configuration->Get<unsigned int>("ING.Engine.terminationBehavior") == 1) {
				system("pause");
			}

			exit(1);

			return false;

		}

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
	Engine* Engine::CreateInstance() {

		return CreateInstance({});

	}

	Engine* Engine::CreateInstance(const std::vector<WString>& argv) {

		Engine* engine = new Engine(argv);

		return engine;

	}

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

}

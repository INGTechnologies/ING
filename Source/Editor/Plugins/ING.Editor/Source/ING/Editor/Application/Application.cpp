
/**
 *	Include Header
 */
#include "Application.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ApplicationWindowSystem
 */
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include ApplicationManager
 */
#include <ING/Application/Manager/Manager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Editor Window
 */
#include <ING/Editor/Window/Window.h>



/**
 *	Include Editor Window System
 */
#include <ING/Editor/Application/WindowSystem/WindowSystem.h>



/**
 *	Include Editor Layout System
 */
#include <ING/Editor/Application/LayoutSystem/LayoutSystem.h>



/**
 *	Include Editor Tab System
 */
#include <ING/Editor/Application/TabSystem/TabSystem.h>



/**
 *	Include Editor Rendering System
 */
#include <ING/Editor/Application/RenderingSystem/RenderingSystem.h>



/**
 *	Include Editor UI System
 */
#include <ING/Editor/Application/UISystem/UISystem.h>



/**
 *	Include Editor Game Application
 */
#include <ING/Editor/GameApplication/GameApplication.h>



/**
 *	Include Layout
 */
#include <ING/Editor/Layout/Layout.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		Application::Application() :
			IApplication(L""),
			Singleton()
		{}

		Application::Application(const WString& configPath, const WString& projectPath) :
			IApplication(configPath),

			projectPath(projectPath),

			gameApplication(0)
		{

			Debug::Log("Start Creating Editor Application");



			SetupRootPaths();



			IApplicationModule* module = new IApplicationModule("ING.Editor", this);

			module->AddDependency("ING");



			AddComponent(new ApplicationLayoutSystem(this));
			AddComponent(new ApplicationTabSystem(this));

			GetWindowSystem()->AddOverride(new ApplicationWindowSystem(GetWindowSystem()));
			GetRenderingSystem()->AddOverride(new ApplicationRenderingSystem(GetRenderingSystem()));
			GetUISystem()->AddOverride(new ApplicationUISystem(GetUISystem()));



			CreateGameApplication();



			Debug::Log("Editor Application Created");

		}

		Application::~Application() {



		}



		/**
		 *	Init, Release Methods
		 */
		bool	Application::Init() {

			Debug::Log("Start Initializing Editor Application");

			if(!IApplication::Init())return false;

			if (!InitGameApplication())return false;

			Debug::Log("Finished Initializing Editor Application");

		}
		void	Application::Release() {

			Debug::Log("Start Releasing Editor Application");

			if(gameApplication != 0)
				gameApplication->Release();

			IApplication::Release();

			Debug::Log("Finished Releasing Editor Application");

		}



		/**
		 *	Methods
		 */
		void	Application::SetupRootPaths() {

			if (!std::filesystem::exists(projectPath)) {

				Debug::Log("Project Config Not Found");

				Release();

				exit(1);

				return;

			}

			Debug::Log("Setup Engine Rootpaths");

			Engine::GetInstance()->SetRootPath(

				L"Editor",

				Path::GetAbsolutePath(L"Game:/")

			);

			Engine::GetInstance()->SetRootPath(

				L"Game",

				projectPath

			);

			configPath = L"Editor:/";

		}

		void Application::CreateGameApplication() {

			gameApplication = new GameApplication(L"Game:/Config.ini");

			ApplicationManager::GetInstance()->SetGameApplication(gameApplication);

		}

		bool Application::InitGameApplication() {

			return gameApplication->Init();
		}

		void Application::PlayGame() {



		}

	}

}
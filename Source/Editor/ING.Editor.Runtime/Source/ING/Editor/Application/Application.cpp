
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
 *	Include ApplicationWindowManager
 */
#include <ING/Application/WindowManager/WindowManager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include GameApplication
 */
#include <ING/Editor/Game/Application/Application.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		Application::Application(const String& configPath, const String& projectPath) :
			IApplication(configPath),

			projectPath(projectPath),

			gameApplication(0)
		{



		}

		Application::~Application() {



		}



		/**
		 *	Init, Release Methods
		 */
		bool	Application::Init() {

			if(!IApplication::Init())return false;

			SetupRootPaths();

			CreateMainWindow();

			CreateGameApplication(); 

		}
		void	Application::Release() {

			if(gameApplication != 0)
				gameApplication->Release();

			IApplication::Release();

			ING::Engine::GetInstance()->Shutdown();

		}



		/**
		 *	Methods
		 */
		void	Application::SetupRootPaths() {

			Engine::GetInstance()->SetRootPath(

				L"Editor",

				Engine::GetInstance()->GetRootPath(L"Game")

			);

			Engine::GetInstance()->SetRootPath(

				L"Game",

				ToWString(projectPath)

			);

		}

		void	Application::CreateMainWindow() {

			GetWindowManager()->AddWindow(
			
				IWindow::Create({

					1600,

					900,

					L"ING.Editor",

					"ING.Editor.MainWindow",

					true

				})
			
			);

			GetWindowManager()->GetWindow("ING.Editor.MainWindow")->GetEvent("DESTROY")->AddListener([](Event* e) {
				
				Application::GetInstance()->Release();
				
			});

		}

		void Application::CreateGameApplication() {

			gameApplication = new GameApplication("Game:/Config.ini");

		}

		void Application::PlayGame() {



		}

	}

}
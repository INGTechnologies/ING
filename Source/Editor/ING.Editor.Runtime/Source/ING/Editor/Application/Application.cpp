
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
#include <ING/Application/Window/Manager/Manager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		Application::Application(const std::string& configPath, const std::string& projectPath) :
			IApplication(configPath),

			projectPath(projectPath)
		{

			SetupRootPaths();

			CreateMainWindow();

		}

		Application::~Application() {



		}



		/**
		 *	Methods
		 */
		void	Application::SetupRootPaths() {

			Engine::GetInstance()->AddRootPath(

				L"Editor",

				Engine::GetInstance()->GetAbsolutePathFromRootPath(L"Game")

			);

			Engine::GetInstance()->AddRootPath(

				L"Game",

				WString(projectPath)

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

				ING::Engine::GetInstance()->Shutdown();
				
			});

		}

	}

}
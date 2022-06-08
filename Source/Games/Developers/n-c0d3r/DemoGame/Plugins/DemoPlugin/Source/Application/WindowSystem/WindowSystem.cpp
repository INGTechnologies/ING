
/**
 *	Include Header
 */
#include "WindowSystem.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Editor Window
 */
#include <ING/Editor/Window/Window.h>



/**
 *	Include Window System
 */
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationWindowSystem::ApplicationWindowSystem(IApplicationComponent* component) :
			ApplicationComponentOverride(component, "EditorWindowSystem")
		{



		}

		ApplicationWindowSystem::~ApplicationWindowSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationWindowSystem::Init()
		{

			Window* mainWindow = new Window(
				{

					"ING.Editor.MainWindow",

					1600,

					900

				}
			);

			mainWindow->GetINGWindow()->GetEvent("DESTROY")->AddListener([](Event* e) {

				ING::Engine::GetInstance()->Shutdown();

			});

			return ApplicationComponentOverride::Init();

		}

		void ApplicationWindowSystem::Release()
		{

			for (auto item = name2WindowMap.begin(); item != name2WindowMap.end();) {

				(item++)->second->Release();

			}

			ApplicationComponentOverride::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationWindowSystem::AddWindow(Window* window) {

			name2WindowMap[window->GetName()] = window;

			GetApplication()->GetWindowSystem()->AddWindow(window->GetINGWindow());

		}

		void	ApplicationWindowSystem::RemoveWindow(Window* window) {

			name2WindowMap.erase(window->GetName());

			GetApplication()->GetWindowSystem()->RemoveWindow(window->GetINGWindow());

		}

		void	ApplicationWindowSystem::Start() {

			ApplicationComponentOverride::Start();

		}

		void	ApplicationWindowSystem::PreUpdate() {

			ApplicationComponentOverride::PreUpdate();

		}

		void	ApplicationWindowSystem::Update() {

			ApplicationComponentOverride::Update();

		}

		void	ApplicationWindowSystem::LateUpdate() {

			ApplicationComponentOverride::LateUpdate();

		}

		void	ApplicationWindowSystem::PreRender() {

			ApplicationComponentOverride::PreRender();

		}

		void	ApplicationWindowSystem::Render() {

			ApplicationComponentOverride::Render();

		}

		void	ApplicationWindowSystem::LateRender() {

			ApplicationComponentOverride::LateRender();

		}

	}
	
}
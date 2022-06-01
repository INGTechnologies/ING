
/**
 *	Include Header
 */
#include "GameApplication.h"



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



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		GameApplication::GameApplication(const WString& configPath) :
			IGameApplication(configPath, "PIE")
		{

			Debug::Log("Start Creating PIE GameApplication");



			Debug::Log("PIE GameApplication Created");

		}

		GameApplication::~GameApplication() {



		}



		/**
		 *	Init, Release Methods
		 */
		bool	GameApplication::Init() {

			Debug::Log("Start Initializing PIE GameApplication");

			if (!IGameApplication::Init())return false;

			Debug::Log("Finished Initializing PIE GameApplication");

		}
		void	GameApplication::Release() {

			Debug::Log("Start Releasing PIE GameApplication");

			IGameApplication::Release();

			Debug::Log("Finished Releasing PIE GameApplication");

		}



		/**
		 *	Methods
		 */
		void	GameApplication::Start() {

			IGameApplication::Start();

		}

		void	GameApplication::PreUpdate() {

			IGameApplication::PreUpdate();

		}

		void	GameApplication::Update() {

			IGameApplication::Update();

		}

		void	GameApplication::LateUpdate() {

			IGameApplication::LateUpdate();

		}

		void	GameApplication::PreRender() {

			IGameApplication::PreRender();

		}

		void	GameApplication::Render() {

			IGameApplication::Render();

		}

		void	GameApplication::LateRender() {

			IGameApplication::LateRender();

		}

	}

}
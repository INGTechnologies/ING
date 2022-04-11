#include "Engine.h"



/**
 *	Include System
 */
#include <ING\Rendering/System/System.h>



/**
 *	Include Shader Manager
 */
#include <ING\Rendering/Shader/Manager/Manager.h>



/**
 *	Include Material Manager
 */
#include <ING\Rendering/Material/Manager/Manager.h>



/**
 *	Include Mesh Manager
 */
#include <ING\Rendering/Mesh/Manager/Manager.h>



/**
 *	Include Scene Manager
 */
#include <ING\Rendering/Scene/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING\Rendering/API/Manager/Manager.h>



/**
 *	Include ScreenManager
 */
#include <ING\Screen/Manager/Manager.h>



/**
 *	Include Screen
 */
#include <ING\Screen/Screen.h>



/**
 *	Include WindowManager
 */
#include <ING\Window/Manager/Manager.h>



/**
 *	Include Window
 */
#include <ING\Window/Window.h>



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Layer Manager
 */
#include <ING\Rendering/Layer/Manager/Manager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ECS Repository Manager
 */
#include <ING/ECS/Repository/Manager/Manager.h>



namespace ING {
	
	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Engine::Engine() {

			Debug::Log("Start Creating Rendering::Engine");

			/**
			 *	Add Squares
			 */
			/* API Manager */
			AddSquare<APIManager>();

			/* Shader Manager */
			AddSquare<ShaderManager>();

			/* Material Manager */
			AddSquare<MaterialManager>();

			/* Mesh Manager */
			AddSquare<MeshManager>();

			/* Scene Manager */
			AddSquare<SceneManager>();

			/* Layer Manager */
			AddSquare<LayerManager>();

			/* System */
			AddSquare<System>();

			Debug::Log("Rendering::Engine Created");

		}

		Engine::~Engine() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool Engine::Init() {

			Debug::Log("Start Initializing Rendering::Engine");

			bool result = Board<Engine>::Init();

			if (result)
				Debug::Log("Rendering::Engine Initialized");
			else {

				Debug::Log("Cant Init Rendering::Engine");

			}

			return result;
		}

		bool Engine::Run() {

			Debug::Log("Start Running Rendering::Engine");

			return Board<Engine>::Run();
		}

		bool Engine::Release() {

			Debug::Log("Start Releasing Rendering::Engine");

			bool result = Board<Engine>::Release();

			if (result)
				Debug::Log("Finished Releasing Rendering::Engine");
			else {

				Debug::Error("Cant Release Rendering::Engine");

			}

			return result;
		}



		/**
		 *	Methods
		 */
		void Engine::FrameUpdate() {

			ECS::RepositoryManager::GetInstance()->PreRender();

			ECS::RepositoryManager::GetInstance()->Render();

			Rendering::System::GetInstance()->FrameUpdate();

			ECS::RepositoryManager::GetInstance()->LateRender();

		}

	}

}
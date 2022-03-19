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



namespace ING {
	
	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Engine::Engine() {

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

		}

		Engine::~Engine() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool Engine::Init() {

			return Board<Engine>::Init();
		}

		bool Engine::Run() {



			return Board<Engine>::Run();
		}

		bool Engine::Release() {



			return Board<Engine>::Release();
		}



		/**
		 *	Methods
		 */
		void Engine::FrameUpdate() {

			Rendering::System::GetInstance()->FrameUpdate();

		}

	}

}
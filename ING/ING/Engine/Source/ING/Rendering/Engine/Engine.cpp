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

	}

}
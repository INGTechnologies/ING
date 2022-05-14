
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SceneManager::SceneManager() {

			Debug::Log("Start Creating Rendering::SceneManager");

			Debug::Log("Rendering::SceneManager Created");

		}

		SceneManager::~SceneManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool SceneManager::Init() {

			Debug::Log("Start Initializing Rendering::SceneManager");

			Debug::Log("Rendering::SceneManager Initialized");

			return true;
		}

		bool SceneManager::Run() {

			Debug::Log("Start Running Rendering::SceneManager");

			return true;
		}

		bool SceneManager::Release() {

			Debug::Log("Start Releasing Rendering::SceneManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::SceneManager");

			return true;
		}

	}
}

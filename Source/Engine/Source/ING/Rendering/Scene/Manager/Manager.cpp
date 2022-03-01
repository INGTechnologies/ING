
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SceneManager::SceneManager() {



		}

		SceneManager::~SceneManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool SceneManager::Init() {



			return true;
		}

		bool SceneManager::Run() {



			return true;
		}

		bool SceneManager::Release() {



			return true;
		}



		/**
		 *	Methods
		 */
		void	SceneManager::AddScene		(Scene* scene) {

			sceneMap[scene->GetName()] = scene;

		}

		void	SceneManager::RemoveScene	(Scene* scene) {

			sceneMap.erase(scene->GetName());

		}

	}
}

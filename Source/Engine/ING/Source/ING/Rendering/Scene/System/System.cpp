
/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h>



/**
 *	Include Layer System
 */
#include <ING/Rendering/Layer/System/System.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SceneSystem::SceneSystem() :
			layerSystem(0)
		{

			layerSystem = new LayerSystem();

		}

		SceneSystem::~SceneSystem() {



		}



		/**
		 *	Release Methods
		 */
		void SceneSystem::Release() {

			delete layerSystem;

			delete this;
		}



		/**
		 *	Methods
		 */
		void	SceneSystem::AddScene		(Scene* scene) {

			sceneMap[scene->GetName()] = scene;

		}

		void	SceneSystem::RemoveScene	(Scene* scene) {

			sceneMap.erase(scene->GetName());

		}

	}
}

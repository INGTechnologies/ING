
/**
 *	Include Header
 */
#include "Scene.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>





namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Scene::Scene(std::string name)
		{

			this->name = name;

			SceneManager::GetInstance()->AddScene(this);

		}

		Scene::~Scene()
		{



		}



		/**
		 *	Release Methods
		 */
		void Scene::Release()
		{

			SceneManager::GetInstance()->RemoveScene(this);

			delete this;

		}

	}

}
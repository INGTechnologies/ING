
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		LayerManager::LayerManager() {

			Debug::Log("Start Creating Rendering::LayerManager");



			Debug::Log("Rendering::LayerManager Created");

		}

		LayerManager::~LayerManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool LayerManager::Init() {

			Debug::Log("Start Initializing Rendering::LayerManager");



			Debug::Log("Rendering::LayerManager Initialized");

			return true;
		}

		bool LayerManager::Run() {

			Debug::Log("Start Running Rendering::LayerManager");

			return true;
		}

		bool LayerManager::Release() {

			Debug::Log("Start Releasing Rendering::LayerManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::LayerManager");

			return true;
		}

	}
}

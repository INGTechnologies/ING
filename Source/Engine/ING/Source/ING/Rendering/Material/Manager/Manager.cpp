
/**
 *	Include Header
 */
#include "Manager.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		MaterialManager::MaterialManager() {

			Debug::Log("Start Creating Rendering::MaterialManager");

			Debug::Log("Rendering::MaterialManager Created");

		}

		MaterialManager::~MaterialManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool MaterialManager::Init() {

			Debug::Log("Start Initializing Rendering::MaterialManager");

			Debug::Log("Rendering::MaterialManager Initialized");

			return true;
		}

		bool MaterialManager::Run() {

			Debug::Log("Start Running Rendering::MaterialManager");

			return true;
		}

		bool MaterialManager::Release() {

			Debug::Log("Start Releasing Rendering::MaterialManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::MaterialManager");

			return true;
		}

	}
}

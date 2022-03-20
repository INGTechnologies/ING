
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
		MeshManager::MeshManager() {

			Debug::Log("Start Creating Rendering::MeshManager");

			Debug::Log("Rendering::MeshManager Created");

		}

		MeshManager::~MeshManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool MeshManager::Init() {

			Debug::Log("Start Initializing Rendering::MeshManager");

			Debug::Log("Rendering::MeshManager Initialized");

			return true;
		}

		bool MeshManager::Run() {

			Debug::Log("Start Running Rendering::MeshManager");

			return true;
		}

		bool MeshManager::Release() {

			Debug::Log("Start Releasing Rendering::MeshManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::MeshManager");

			return true;
		}

	}
}

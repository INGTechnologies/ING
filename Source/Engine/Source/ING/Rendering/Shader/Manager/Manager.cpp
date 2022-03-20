
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
		ShaderManager::ShaderManager() {

			Debug::Log("Start Creating Rendering::ShaderManager");

			Debug::Log("Rendering::ShaderManager Created");

		}

		ShaderManager::~ShaderManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool ShaderManager::Init() {

			Debug::Log("Start Initializing Rendering::ShaderManager");

			Debug::Log("Rendering::ShaderManager Initialized");

			return true;
		}

		bool ShaderManager::Run() {

			Debug::Log("Start Running Rendering::ShaderManager");

			return true;
		}

		bool ShaderManager::Release() {

			Debug::Log("Start Releasing Rendering::ShaderManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::ShaderManager");

			return true;
		}

	}
}

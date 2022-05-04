
/**
 *	Include Header
 */
#include "Engine.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		Engine::Engine() {

			Debug::Log("Start Creating Reflection::Engine");



			Debug::Log("Reflection::Engine Created");

		}

		Engine::~Engine() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool Engine::Init() {

			Debug::Log("Start Initializing Reflection::Engine");



			Debug::Log("Reflection::Engine Initialized");

			return true;
		}

		bool Engine::Run() {

			Debug::Log("Start Running Reflection::Engine");

			return true;
		}

		bool Engine::Release() {

			Debug::Log("Start Releasing Reflection::Engine");

			delete this;

			Debug::Log("Finished Releasing Reflection::Engine");

			return true;
		}

	}

}

/**
 *	Include Header
 */
#include "Application.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		GameApplication::GameApplication(const WString& configPath) :
			IApplication(configPath)
		{

			Debug::Log("Start Creating Game Application");



			Debug::Log("Game Application Created");

		}

		GameApplication::~GameApplication() {



		}



		/**
		 *	Release Methods
		 */
		bool	GameApplication::Init() {

			Debug::Log("Start Initializing Game Application");

			if (!IApplication::Init()) {

				Debug::Log("Cant Initialize Game Application");

				return false;
			}

			Debug::Log("Finished Initializing Game Application");

			return true;

		}
		void	GameApplication::Release() {

			Debug::Log("Start Releasing Game Application");

			IApplication::Release();

			Debug::Log("Finished Releasing Game Application");

		}

	}

}
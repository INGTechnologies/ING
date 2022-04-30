
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



		}

		GameApplication::~GameApplication() {



		}



		/**
		 *	Release Methods
		 */
		bool	GameApplication::Init() {

			return IApplication::Init();

		}
		void	GameApplication::Release() {

			IApplication::Release();

		}

	}

}
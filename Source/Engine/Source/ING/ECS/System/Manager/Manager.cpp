
/**
 *	Include Header
 */
#include "Manager.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		SystemManager::SystemManager() {



		}

		SystemManager::~SystemManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool SystemManager::Init() {



			return true;
		}

		bool SystemManager::Run() {



			return true;
		}

		bool SystemManager::Release() {



			return Square::Release();
		}

	}

}
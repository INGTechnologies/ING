
/**
 *	Include Header
 */
#include "System.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		System::System() {



		}

		System::~System() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool System::Init() {



			return true;
		}

		bool System::Run() {



			return true;
		}

		bool System::Release() {



			return Square::Release();
		}

	}

}
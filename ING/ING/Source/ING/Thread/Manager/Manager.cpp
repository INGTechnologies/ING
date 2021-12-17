#include "Manager.h"

namespace ING {


	Thread::Manager::Manager() {



	}

	Thread::Manager::~Manager() {



	}



	/*
	 *	Events
	 */
	bool Thread::Manager::Init() {

		/*
		 *	Create Main Thread
		 */

		mainThread = new Thread();


		return true;
	}

	bool Thread::Manager::Run() {



		return true;
	}

	bool Thread::Manager::Release() {



		return true;
	}
}
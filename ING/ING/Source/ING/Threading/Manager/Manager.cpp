#include "Manager.h"


#include <ING/Utils/Utils.h>

using namespace ING::Utils;




namespace ING {

	/*
	 *	Constructors And Destructor
	 */
	Thread::Manager::Manager() {



	}

	Thread::Manager::~Manager() {



	}



	/*
	 *	Init, Run, Release Methods
	 */
	bool Thread::Manager::Init() {

		/*
		 *	Create Main Thread
		 */

		threadMap[0] = new Thread();
		threadMap[0]->id = 0;

		return true;
	}

	bool Thread::Manager::Run() {



		return true;
	}

	bool Thread::Manager::Release() {


		threadMap.clear();

		return true;
	}

	IMPLEMENT_SINGLETON(Thread::Manager);

}

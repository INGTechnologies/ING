
/**
 *	Include Header
 */
#include "Thread.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Thread::Thread(ThreadFunction function) {

		this->function = function;

	}

	Thread::~Thread() {



	}



	/**
	 *	Start, Join, Kill Methods
	 */
	void Thread::Start() {



	}

	void Thread::Join() {



	}

	void Thread::Kill() {



	}

}
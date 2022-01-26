
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
	Thread::Thread() {

		isReady				= false;

		isSTDThreadCreated	= false;

	}

	Thread::Thread(ThreadFunction function) {

		isReady = false;

		isSTDThreadCreated = false;

		this->function = function;

	}

	Thread::~Thread() {



	}



	/**
	 *	Start, Join, Kill Methods
	 */
	void Thread::Start() {

		std::thread newSTDThread([](Thread* thread) {
			
			thread->GetFunction()(thread);
		
		}, this);

		stdThread.swap(newSTDThread);

		isSTDThreadCreated = true;

		isReady = true;

	}

	void Thread::WaitReady() {

		while (!isReady) {



		}

	}

	void Thread::Join() {

		stdThread.join();

		delete this;

	}

	void Thread::Kill() {

		stdThread.detach();

		delete this;

	}

}
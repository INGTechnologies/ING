
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

		isStarted = false;

	}

	Thread::Thread(ThreadFunction function) {

		isReady = false;

		isSTDThreadCreated = false;

		isStarted = false;

		this->function = function;

	}

	Thread::~Thread() {



	}



	/**
	 *	Start, Join, Kill, Release Methods
	 */
	void Thread::Start() {

		std::thread newSTDThread([](Thread* thread) {
			
			thread->GetFunction()(thread);
		
		}, this);

		stdThread.swap(newSTDThread);

		isSTDThreadCreated = true;

		isReady = true;

		isStarted = true;

	}

	void Thread::WaitReady() {

		while (!isReady) {



		}

	}

	void Thread::Join() {

		if (isStarted) {

			stdThread.join();

		}

		Release();

	}

	void Thread::Kill() {

		stdThread.detach();

		Release();

	}

	void Thread::Release() {

		delete this;

	}

}
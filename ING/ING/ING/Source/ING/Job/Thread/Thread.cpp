
/**
 *	Include Header
 */
#include "Thread.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Thread
 */
#include <ING/Thread/Thread.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	JobThread::JobThread() {



	}

	JobThread::~JobThread() {



	}



	/**
	 *	Start, Join, Loop Method
	 */
	void JobThread::Start() {

		ingThread = new Thread([](Thread* ingThread) {

			JobThread* jobThread = ingThread->params[0].As<JobThread*>();


			
			ingThread->params.~Ref();
			
		});

		ingThread->params = new MultiTypeArray(1);

		ingThread->params[0] = this;

		ingThread->Start();

	}

	void JobThread::Join() {

		delete ingThread;

		delete this;

	}

	void JobThread::Loop() {



	}

}
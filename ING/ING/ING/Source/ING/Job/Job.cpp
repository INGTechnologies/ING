
/**
 *	Include Header
 */
#include "Job.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Job::Job() {

		isDone = false;

	}

	Job::Job(void (*executor)(Job* job)):
		Job()
	{

		this->executor = executor;

	}

	Job::~Job() {



	}



	/**
	 *	Schedule, Complete Methods
	 */
	void Job::Schedule() {

		isDone = false;

		executor(this);

		isDone = true;

	}

	void Job::Complete() {

		while (!isDone) {



		}

	}

}

/**
 *	Include Header
 */
#include "Job.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include JobSystem
 */
#include <ING/Job/System/System.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Job::Job() {

		isRunning	= false;

		isDone		= false;

		queue		= 0;

	}

	Job::Job(void (*executor)(Job* job)):
		Job()
	{

		this->executor = executor;

	}

	Job::~Job() {

		

	}



	/**
	 *	Run, Schedule, Complete Methods
	 */
	void Job::Run() {

		executor(this);

		isDone = true;

		isRunning = false;

	}

	void Job::Schedule() {

		isDone		= false;

		isRunning	= true;

		JobSystem::GetInstance()->ScheduleJob(this);

	}

	void Job::Complete() {

		while (!isDone) {



		}

	}

}
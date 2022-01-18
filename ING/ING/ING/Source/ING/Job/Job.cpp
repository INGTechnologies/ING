
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

		scheduler	= [](Job* job, void* customData) {
		
			job->SetIsDone(false);

			job->SetIsRunning(true);

			JobSystem::GetInstance()->ScheduleJob(job, nullptr);
		
		};

		runner		= [](Job* job, void* customData) {

			job->GetExecutor()(job,nullptr);

			job->SetIsDone(true);

			job->SetIsRunning(false);

		};

		executor	= [](Job* job, void* customData) {



		};

	}

	Job::Job(Func executor):
		Job()
	{

		this->executor = executor;

	}

	Job::~Job() {

		

	}



	/**
	 *	Run, Schedule, Complete Methods
	 */
	void Job::Run(void* customData) {

		runner(this, customData);

	}

	void Job::Schedule() {

		scheduler(this, nullptr);

	}

	void Job::Complete() {

		while (!isDone) {



		}

	}

	void Job::Release() {

		delete this;

	}

}
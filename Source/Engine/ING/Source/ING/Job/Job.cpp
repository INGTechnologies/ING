
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
	IJob::IJob() {

		isRunning	= false;

		isDone		= false;

		queue		= 0;

		scheduler	= [](IJob* job, void* customData) {
		
			job->SetIsDone(false);

			job->SetIsRunning(true);

			JobSystem::GetInstance()->ScheduleJob(job, nullptr);
		
		};

		runner		= [](IJob* job, void* customData) {

			job->GetExecutor()(job,nullptr);

			job->SetIsDone(true);

			job->SetIsRunning(false);

		};

		executor	= [](IJob* job, void* customData) {



		};

	}

	IJob::IJob(Func executor):
		IJob()
	{

		this->executor = executor;

	}

	IJob::~IJob() {

		

	}



	/**
	 *	Run, Schedule, Complete Methods
	 */
	void IJob::Run(void* customData) {

		runner(this, customData);

	}

	void IJob::Schedule() {

		scheduler(this, nullptr);

	}

	void IJob::Complete() {

		while (!isDone) {



		}

	}

	void IJob::Release() {

		delete this;

	}

}
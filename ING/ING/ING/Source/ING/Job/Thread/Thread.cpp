
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



/**
 *	Include JobSystem
 */
#include <ING/Job/System/System.h>



/**
 *	Include Job
 */
#include <ING/Job/Job.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	JobThread::JobThread() {



	}

	JobThread::~JobThread() {



	}



	/**
	 *	Queue Jobs
	 */
	void JobThread::ScheduleJob(Job* job) {

		mutex.lock();

		queueJobs.Add(job);

		mutex.unlock();

	}



	/**
	 *	Start, Join, Loop Method
	 */
	void JobThread::Start() {

		ingThread = new Thread([](Thread* ingThread) {

			JobThread* jobThread = ingThread->params[0].As<JobThread*>();
			
			ingThread->params.~Ref();

			jobThread->Loop();
			
		});

		ingThread->params = new MultiTypeArray(1);

		ingThread->params[0] = this;

		ingThread->Start();

	}

	void JobThread::Join() {

		queueJobs.Foreach([](Job*& job) {
			
			delete job;
			
		});

		queueJobs.Clear();

		delete ingThread;

		delete this;

	}

	void JobThread::Loop() {

		while (JobSystem::GetInstance()->IsRunning()) {

			mutex.lock();





			//Compute Total Queue

			MultiTypeArray params(1);

			params[0] = (unsigned int)0;

			queueJobs.Foreach([](Job*& job, MultiTypeArray& params) {

				params[0] = (unsigned int)(params[0].As<unsigned int>() + job->GetQueue());

			}, params);


			forTotalQueue_Mutex.lock();

			totalQueue = params[0].As<unsigned int>();

			forTotalQueue_Mutex.unlock();


			params.Clear();





			queueJobs.Foreach([](Job*& job) {

				job->Run();

			});

			queueJobs.Clear();



			mutex.unlock();

		}

	}

}
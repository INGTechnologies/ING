
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
	JobThread::JobThread() :
		ingThread(0)
	{



	}

	JobThread::~JobThread() {



	}



	/**
	 *	Queue Jobs
	 */
	void JobThread::ScheduleJob(IJob* job, void* customData) {

		bool isNeedLockMutex = true;

		if (std::this_thread::get_id() == ingThread->GetSTDThread().get_id()) {

			isNeedLockMutex = false;

		}



		if(isNeedLockMutex) mutex.lock();



		queueJobs.Add(job);

		customDatas.Add(customData);



		forTotalQueue_Mutex.lock();

		totalQueue += job->GetQueue();

		forTotalQueue_Mutex.unlock();



		if (isNeedLockMutex) mutex.unlock();

	}



	/**
	 *	Start, Join, Loop Method
	 */
	void JobThread::Start() {

		ingThread = new Thread([](Thread* ingThread) {

			ingThread->WaitReady();

			ThreadManager::GetInstance()->RegisterThread(ingThread);

			JobThread* jobThread = ingThread->params[0].As<JobThread*>();
			
			ingThread->params.~Reference();

			jobThread->Loop();

			ThreadManager::GetInstance()->UnregisterThread(ingThread);
			
		});

		ingThread->params = new MultiTypeArray(1);

		ingThread->params[0] = this;

		ingThread->Start();

	}

	void JobThread::Join() {

		ingThread->Join();

		queueJobs.Foreach([](IJob*& job) {
			
			delete job;
			
		});

		queueJobs.Clear();

		delete this;

	}

	void JobThread::Loop() {

		while (JobSystem::GetInstance()->IsRunning()) {

			mutex.lock();

			List<IJob*>::Node* node = queueJobs.GetHeadNode();

			List<void*>::Node* customData_node = customDatas.GetHeadNode();

			while (node != nullptr) {
				List<IJob*>::Node* nextNode = node->next;
				List<void*>::Node* customData_next_node = customData_node->next;

				IJob* job = *((IJob**)(node->pValue));

				job->Run(*((void**)(customData_node->pValue)));

				customData_node = customData_next_node;
				node = nextNode;
			}

			queueJobs.Clear();

			customDatas.Clear();

			forTotalQueue_Mutex.lock();

			totalQueue = 0;

			forTotalQueue_Mutex.unlock();

			mutex.unlock();

		}

	}

}
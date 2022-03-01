
/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include JobThread
 */
#include <ING/Job/Thread/Thread.h>



/**
 *	Include Job
 */
#include <ING/Job/Job.h>



/**
 *	Include System
 */
#include <ING/System/System.h>



/**
 *	Include ApplicationThreadManager
 */
#include <ING/Application/Thread/Manager/Manager.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	JobSystem::JobSystem() {

		isRunning = false;
		threadCount = 1;



		int maxThreadCount = 3;

		APPLICATION_CONFIG_PROP(unsigned int, "ING::JobSystem::maxThreadCount", (unsigned int)maxThreadCount);

		maxThreadCount = APPLICATION_GET_CONFIG_PROP(unsigned int, "ING::JobSystem::maxThreadCount");



		int defaultThreadCount = System::GetInstance()->GetNumberOfProcessors();

		defaultThreadCount = (

			System::GetInstance()->GetNumberOfProcessors()

			- ApplicationThreadManager::GetInstance()->GetThreadList().GetSize()

			- 1
			
		);

		if (defaultThreadCount <= 0) {

			defaultThreadCount = 1;

		}

		if (defaultThreadCount > maxThreadCount && maxThreadCount != -1) {

			defaultThreadCount = maxThreadCount;
			
		}

		APPLICATION_CONFIG_PROP(unsigned int, "ING::JobSystem::threadCount", (unsigned int)defaultThreadCount);

	}

	JobSystem::~JobSystem() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool JobSystem::Init() {

		RecreateThreads();

		return Square::Init();
	}

	bool JobSystem::Run() {

		RunThreads();

		return Square::Run();
	}

	bool JobSystem::Release() {

		JoinThreads();

		return Square::Release();
	}



	/**
	 *	JobThreads Management Methods
	 */
	void JobSystem::RecreateThreads() {

		JoinThreads();

		CreateThreads();

	}

	void JobSystem::CreateThreads() {

		threadCount = Application::GetInstance()->GetConfiguration()->Get<unsigned int>("ING::JobSystem::threadCount");

		threads.resize(threadCount);

		for (unsigned int i = 0; i < threadCount; ++i) {

			threads[i] = new JobThread();

		}

	}

	void JobSystem::RunThreads() {

		isRunning = true;

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			threads[i]->Start();

		}

	}

	void JobSystem::JoinThreads() {

		this->isRunning = false;

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			threads[i]->Join();

		}

		threads.clear();

	}

	void JobSystem::DeleteThreads() {

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			delete threads[i];

		}

		threads.clear();

	}



	/**
	 *	Job Management Methods
	 */
	void JobSystem::ScheduleJob(IJob* job, void* customData) {

		//Find Most Free Thread
		unsigned int mostFreeThreadIndex = 0;

		unsigned int currentThreadCount = threads.size();

		if (currentThreadCount == 0) return;

		unsigned int minQueue = 0;

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			threads[i]->GetForTotalQueue_Mutex().lock();

			unsigned currentThreadTotalQueue = threads[i]->GetTotalQueue();

			if (currentThreadTotalQueue == 0) {

				mostFreeThreadIndex = i;

				minQueue = 0;

				threads[i]->GetForTotalQueue_Mutex().unlock();

				break;

			}

			if (currentThreadTotalQueue < minQueue || i == 0) {

				mostFreeThreadIndex = i;

				minQueue = currentThreadTotalQueue;

			}

			threads[i]->GetForTotalQueue_Mutex().unlock();

		}



		//Schedule Job
		threads[mostFreeThreadIndex]->ScheduleJob(job, customData);

	}

}
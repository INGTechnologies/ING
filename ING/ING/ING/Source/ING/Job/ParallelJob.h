#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Job
 */
#include <ING/Job/Job.h>



 /**
  *	Include JobSystem
  */
#include <ING/Job/System/System.h>



/**
 *	Include Mutex
 */
#include <mutex>



namespace ING {

	struct ParallelJob : Job {

	public:
		typedef void (*SecondExecutor)(ParallelJob*, unsigned int);



		/**
		 *	Constructors And Destructor
		 */
	public:
		ParallelJob() {

			threadDoneCount = 0;

			executor = [](Job* job, void* pIndex) -> void {

				unsigned int index = *((unsigned int*)pIndex);

				((ParallelJob*)job)->GetSecondExecutor()((ParallelJob*)job, index);

				delete pIndex;

			};

			runner = [](Job* job, void* pIndex) {

				unsigned int index = *((unsigned int*)pIndex);

				job->GetExecutor()(job, pIndex);

				((ParallelJob*)job)->GetMutex().lock();

				((ParallelJob*)job)->threadDoneCount++;

				if (((ParallelJob*)job)->threadDoneCount == ((ParallelJob*)job)->GetThreadCount()) {

					job->SetIsDone(true);

					job->SetIsRunning(false);

				}

				((ParallelJob*)job)->GetMutex().unlock();

			};

			scheduler = [](Job* job, void* customData) {

				((ParallelJob*)job)->threadDoneCount = 0;

				job->SetIsDone(false);

				job->SetIsRunning(true);

				for (unsigned int i = 0; i < ((ParallelJob*)job)->GetThreadCount(); ++i) {

					unsigned int* customData = new unsigned int(i);

					JobSystem::GetInstance()->ScheduleJob(job, customData);

				}

			};

		}

		ParallelJob(unsigned int threadCount, SecondExecutor secondExecutor) :
			ParallelJob()
		{

			this->secondExecutor = secondExecutor;

			this->threadCount = threadCount;

		}

		~ParallelJob() {



		}



	protected:
		unsigned int threadCount;

	public:
		unsigned int GetThreadCount() { return threadCount; }



	public:
		unsigned int threadDoneCount;



	protected:
		SecondExecutor secondExecutor;

	public:
		SecondExecutor GetSecondExecutor() {

			return secondExecutor;

		}



	protected:
		std::mutex mutex;

	public:
		std::mutex& GetMutex() { return mutex; }


	};

}
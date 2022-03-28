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

	/**
	 *	Interface Class
	 */
	struct IParallelJob : IJob {

	public:
		typedef void (*SecondExecutor)(IParallelJob*, unsigned int);



		/**
		 *	Constructors And Destructor
		 */
	public:
		IParallelJob() {

			threadDoneCount = 0;

			executor = [](IJob* job, void* pIndex) -> void {

				unsigned int index = *((unsigned int*)pIndex);

				((IParallelJob*)job)->GetSecondExecutor()((IParallelJob*)job, index);

				delete pIndex;

			};

			runner = [](IJob* job, void* pIndex) {

				unsigned int index = *((unsigned int*)pIndex);

				job->GetExecutor()(job, pIndex);

				((IParallelJob*)job)->GetMutex().lock();

				((IParallelJob*)job)->threadDoneCount++;

				if (((IParallelJob*)job)->threadDoneCount == ((IParallelJob*)job)->GetThreadCount()) {

					job->SetIsDone(true);

					job->SetIsRunning(false);

				}

				((IParallelJob*)job)->GetMutex().unlock();

			};

			scheduler = [](IJob* job, void* customData) {

				((IParallelJob*)job)->threadDoneCount = 0;

				job->SetIsDone(false);

				job->SetIsRunning(true);

				for (unsigned int i = 0; i < ((IParallelJob*)job)->GetThreadCount(); ++i) {

					unsigned int* customData = new unsigned int(i);

					JobSystem::GetInstance()->ScheduleJob(job, customData);

				}

			};

		}

		IParallelJob(unsigned int threadCount, SecondExecutor secondExecutor) :
			IParallelJob()
		{

			this->secondExecutor = secondExecutor;

			this->threadCount = threadCount;

		}

		~IParallelJob() {



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



	/**
	 *	Main Class
	 */
	template<typename T>
	struct ParallelJob : IParallelJob {

		/**
		 *	Constructors And Destructor
		 */
	public:
		ParallelJob(unsigned int threadCount) :
			IParallelJob(

				threadCount,

				[](IParallelJob* job, unsigned int index) -> void {

					((T*)job)->Execute(index);

				}

			)
		{



		}

		~ParallelJob() {



		}


	};

}
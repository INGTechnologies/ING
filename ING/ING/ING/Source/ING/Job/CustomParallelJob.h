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
 *	Include Vector
 */
#include <vector>



namespace ING {

	template<typename T>
	struct CustomParallelJob : Job {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomParallelJob() {

			executor = [](Job* job, void* pIndex) -> void {

				unsigned int index = *((unsigned int*)pIndex);

				((T*)job)->Execute(index);

				delete pIndex;

			};

			runner = [](Job* job, void* pIndex) {
				
				unsigned int index = *((unsigned int*)pIndex);

				job->GetExecutor()(job, pIndex);

				job->SetIsDone(true);

				job->SetIsRunning(false);

			};

			scheduler = [](Job* job, void* customData) {

				job->SetIsDone(false);

				job->SetIsRunning(true);

				for (unsigned int i = 0; i < ((CustomParallelJob<T>*)job)->GetThreadCount(); ++i) {

					unsigned int* customData = new unsigned int(i);

					JobSystem::GetInstance()->ScheduleJob(job, customData);

				}

			};

		}

		CustomParallelJob(unsigned int threadCount) :
			CustomParallelJob()
		{

			this->threadCount = threadCount;

		}

		~CustomParallelJob() {



		}



	protected:
		unsigned int threadCount;

	public:
		unsigned int GetThreadCount() { return threadCount; }


	};

}
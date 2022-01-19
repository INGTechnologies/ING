#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include ParallelJob
 */
#include <ING/Job/ParallelJob.h>



namespace ING {

	template<typename T>
	struct CustomParallelJob : ParallelJob {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomParallelJob(unsigned int threadCount) :
			ParallelJob(

				threadCount,

				[](ParallelJob* job, unsigned int index) -> void {

					((T*)job)->Execute(index);

				}

			)
		{



		}

		~CustomParallelJob() {



		}


	};

}
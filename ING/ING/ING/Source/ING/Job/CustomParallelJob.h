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
 *	Include ParallelJob
 */
#include <ING/Job/ParallelJob.h>



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
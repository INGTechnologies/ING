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



namespace ING {

	template<typename T>
	struct CustomJob  : Job {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomJob() {

			executor = [](Job* job, void* customData) -> void{
			
				((T*)job)->Execute();
			
			};

		}

		~CustomJob() {



		}

	};

}
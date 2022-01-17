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
 *	Include Function
 */
#include <functional>



namespace ING {

	typedef void (*JobExecutor)(void* job);



	struct ING_API Job {

		/**
		 *	Constructors And Destructor
		 */
	public:
		Job();
		Job(void (*executor)(Job* job));
		~Job();



	protected:
		void (*executor)(Job* job);



	private:
		bool isDone;



		/**
		 *	Schedule, Complete Method
		 */
	public:
		void Schedule();
		void Complete();

	};


}
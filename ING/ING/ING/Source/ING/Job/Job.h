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


	struct ING_API Job {

		/**
		 *	Nested Members
		 */
	public:
		typedef void (*Func)		(Job* job, void* customData);



		/**
		 *	Constructors And Destructor
		 */
	public:
		Job();
		Job(Func executor);
		~Job();



		/**
		 *	Virtual Methods
		 */
	protected:
		Func executor;
		Func scheduler;
		Func runner;

	public:
		Func GetExecutor() {

			return executor;

		}

		Func GetScheduler() {

			return scheduler;

		}

		Func GetRunner() {

			return runner;

		}



	private:
		bool			isRunning;
		bool			isDone;
		unsigned int	queue;

	public:

		void			SetIsRunning(bool value) 
		{

			isRunning = value;

		}

		void			SetIsDone(bool value) 
		{

			isDone = value;

		}

		bool			IsDone() { return isDone; }

		void			SetQueue(unsigned int queue) 
		{

			if (isRunning || isDone) return;

			this->queue = queue;

		}

		unsigned int	GetQueue() 
		{

			return queue;

		}
		



		/**
		 *	Run, Schedule, Complete Method
		 */
	public:
		void Run(void* customData);
		void Schedule();
		void Complete();

	};


}
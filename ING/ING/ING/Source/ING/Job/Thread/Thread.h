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
 *	Include Mutex
 */
#include <mutex>



namespace ING {

	class Job;

	class Thread;

	class ING_API JobThread {

		/**
		 *	Constructors And Destructor
		 */
	public:
		JobThread();
		~JobThread();



		/**
		 *	ING Thread
		 */
	private:
		Thread* ingThread;

	public:
		Thread* GetINGThread() {

			return ingThread;

		}
		


		/**
		 *	Mutex
		 */
	private:
		std::mutex mutex;
		std::mutex forTotalQueue_Mutex;

	public:
		std::mutex& GetMutex() {

			return mutex;

		}

		std::mutex& GetForTotalQueue_Mutex() {

			return forTotalQueue_Mutex;

		}



		/**
		 *	Queue Jobs
		 */
	private:
		List<Job*> queueJobs;

	public:
		void ScheduleJob(Job* job);



		/**
		 *	Total Queue
		 */
	private:
		unsigned int totalQueue;

	public:
		unsigned int GetTotalQueue() {

			return totalQueue;

		}



		/**
		 *	Start, Join, Loop Method
		 */
	public:
		void Start();
		void Join();
		void Loop();

	};

}
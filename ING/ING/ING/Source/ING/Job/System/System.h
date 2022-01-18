#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Vector
 */
#include <vector>



namespace ING {

	class JobThread;

	class Job;

	class ING_API JobSystem :
		public Singleton<JobSystem>,
		public Square
	{
		 
		/**
		 *	Constructors And Destructor
		 */
	public:
		JobSystem();
		~JobSystem();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	threadCount
		 */
	private:
		unsigned int threadCount;

	public:
		unsigned int GetThreadCount() {

			return threadCount;

		}



		/**
		 *	isRunning
		 */
	private:
		bool isRunning;

	public:
		bool IsRunning() {

			return isRunning;

		}



		/**
		 *	jobThreads
		 */
	private:
		std::vector<JobThread*> threads;



		/**
		 *	JobThreads Management Methods
		 */
	public:
		void RecreateThreads();
		void CreateThreads();
		void RunThreads();
		void JoinThreads();
		void DeleteThreads();



		/**
		 *	Job Management Methods
		 */
	public:
		void ScheduleJob(Job* job, void* customData);

	};


}
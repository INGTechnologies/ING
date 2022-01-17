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



namespace ING {

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
		 *	Start, Join, Loop Method
		 */
	public:
		void Start();
		void Join();
		void Loop();

	};

}
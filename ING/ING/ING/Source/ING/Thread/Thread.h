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
 *	Include STD Thread
 */
#include <thread>



 /**
  *	Include Thread Manager
  */
#include <ING/Thread/Manager/Manager.h>



  /**
   *	Include MultiTypeArray
   */
#include <ING/Utils/MultiTypeArray/MultiTypeArray.h>



namespace ING {

	class ING_API Thread {

		/**
		 *	Constructors And Destructor
		 */
	public:
		friend class ThreadManager;



		/**
		 *	Type Definitions;
		 */
	public:
		typedef void (*ThreadFunction)(Thread* thread);



		/**
		 *	Constructors And Destructor
		 */
	public:
		Thread(ThreadFunction function);
		~Thread();



		/**
		 *	STDThread And Function	
		 */
	private:
		std::thread stdThread;
		ThreadFunction function;



	public:
		MultiTypeArray* params;



		/**
		 *	Start, Join, Kill Methods
		 */
	public:
		void Start();
		void Join();
		void Kill();

	};


}
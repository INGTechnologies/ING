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
	private:
		Thread();
		
	public:
		Thread(ThreadFunction function);
		~Thread();



		/**
		 *	STDThread, Function And ID	
		 */
	private:
		std::thread stdThread;
		ThreadFunction function;
		unsigned int id;
		bool isReady;
		bool isSTDThreadCreated;
		bool isStarted;

	public:
		unsigned int&	GetID() {

			return id;

		}

		ThreadFunction& GetFunction() {

			return function;

		}

		std::thread&	GetSTDThread() {

			return stdThread;

		}

		bool			IsStarted() {

			return isStarted;

		}



	public:
		MultiTypeArray::Reference params;



		/**
		 *	Start, WaitReady, Join, Kill, Release Methods
		 */
	public:
		void Start();
		void WaitReady();
		void Join();
		void Kill();
		virtual void Release();

	};


}
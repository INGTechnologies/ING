
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Thread
 */
#include "../Thread.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ThreadManager::ThreadManager() {



	}

	ThreadManager::~ThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ThreadManager::Init() {

		//Create Main Thread
		threadMap[0] = new Thread();

		threadMap[0]->id = 0;

		threadIdMap[std::this_thread::get_id()] = 0;

		threadIdGenerator.RegisterUInt16Id(0);

		return true;
	}

	bool ThreadManager::Run() {



		return true;
	}

	bool ThreadManager::Release() {

		threadIdGenerator.ClearIds();

		threadMap.clear();

		threadIdMap.clear();

		return true;
	}



	/**
	 *	Thread Management
	 */
	void ThreadManager::RegisterThread(Thread* thread) {
		
		mutex.lock();

		thread->id = threadIdGenerator.GenUInt16();

		threadMap[thread->id] = thread;

		threadIdMap[thread->stdThread.get_id()] = thread->id;

		mutex.unlock();
		
	}

	void ThreadManager::UnregisterThread(Thread* thread) {

		threadIdGenerator.RemoveUInt16Id(thread->GetID());

		threadMap.erase(thread->GetID());

		threadIdMap.erase(thread->GetSTDThread().get_id());

	}

	Thread* ThreadManager::ThisThread() {

		return threadMap[threadIdMap[std::this_thread::get_id()]];

	}

}


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



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ThreadManager::ThreadManager() {

		Debug::Log("Start Creating ThreadManager");

		Debug::Log("ThreadManager Created");

	}

	ThreadManager::~ThreadManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ThreadManager::Init() {

		Debug::Log("Start Initializing ThreadManager");

		//Create Main Thread
		threadMap[0] = new Thread();

		threadMap[0]->id = 0;

		threadIdMap[std::this_thread::get_id()] = 0;

		threadIdGenerator.RegisterUInt32Id(0);

		Debug::Log("ThreadManager Initialized");

		return true;
	}

	bool ThreadManager::Run() {

		Debug::Log("Start Running ThreadManager");

		return true;
	}

	bool ThreadManager::Release() {

		Debug::Log("Start Releasing ThreadManager");

		threadIdGenerator.ClearIds();

		threadMap.clear();

		threadIdMap.clear();

		Debug::Log("Finished Releasing ThreadManager");

		return Square::Release();
	}



	/**
	 *	Thread Management
	 */
	void ThreadManager::RegisterThread(Thread* thread) {
		
		mutex.lock();

		thread->id = threadIdGenerator.GenUInt32();

		threadMap[thread->id] = thread;

		threadIdMap[thread->stdThread.get_id()] = thread->id;

		mutex.unlock();
		
	}

	void ThreadManager::UnregisterThread(Thread* thread) {

		threadIdGenerator.RemoveUInt32Id(thread->GetID());

		threadMap.erase(thread->GetID());

		threadIdMap.erase(thread->GetSTDThread().get_id());

	}

	Thread* ThreadManager::ThisThread() {

		return threadMap[threadIdMap[std::this_thread::get_id()]];

	}

}

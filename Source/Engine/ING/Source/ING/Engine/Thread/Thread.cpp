
/**
 *	Include Header
 */
#include "Thread.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Engine Thread Manager
 */
#include <ING/Engine/Thread/Manager/Manager.h>



String str = "";



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EngineThread::EngineThread(UpdateFunction updateFunction) : 
		Thread([](Thread* thread) {

			thread->WaitReady();

			ThreadManager::GetInstance()->RegisterThread(thread);
			
			EngineThread* applicationThread = (EngineThread*)thread;

			while (Engine::GetInstance()->GetState() == RUNNING_APPLICATION_STATE) {

				applicationThread->Update();

			}

			ThreadManager::GetInstance()->UnregisterThread(thread);
			
		}), 
		node(0)
	{

		isFrameStart = false;

		isFrameEnd = true;

		this->updateFunction = updateFunction;

	}

	EngineThread::~EngineThread() {



	}



	/**
	 *	Release Method
	 */
	void EngineThread::Release() {

		Thread::Release();

	}



	/**
	 *	StartUpdate, Update, WaitUpdate Methods
	 */
	void EngineThread::StartUpdate() {

		mutex.lock();

		isFrameStart	= true;

		isFrameEnd		= false;

		mutex.unlock();

	}

	void EngineThread::Update() {

		while (true) {

			mutex.lock();

			if (Engine::GetInstance()->GetState() != RUNNING_APPLICATION_STATE) {

				isFrameStart = false;

				isFrameEnd = true;

				mutex.unlock();

				return;

			}

			if (isFrameStart) {



				updateFunction(this);



				isFrameStart = false;

				isFrameEnd = true;

				mutex.unlock();

				return;

			}

			mutex.unlock();
		
		}

	}

	void EngineThread::EndUpdate() {

		while (true) {

			mutex.lock();

			if (isFrameEnd) {

				mutex.unlock();

				return;

			}

			mutex.unlock();
		}

	}

}

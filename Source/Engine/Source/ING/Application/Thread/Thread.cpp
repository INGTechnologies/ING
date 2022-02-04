
/**
 *	Include Header
 */
#include "Thread.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Thread Manager
 */
#include <ING/Application/Thread/Manager/Manager.h>



std::string str = "";



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationThread::ApplicationThread(UpdateFunction updateFunction) : Thread([](Thread* thread) {

		thread->WaitReady();

		ThreadManager::GetInstance()->RegisterThread(thread);
			
		ApplicationThread* applicationThread = (ApplicationThread*)thread;

		while (Application::GetInstance()->GetState() == RUNNING_APPLICATION_STATE) {

			applicationThread->Update();

		}

		ThreadManager::GetInstance()->UnregisterThread(thread);
			
	})
	{

		isFrameStart = false;

		isFrameEnd = true;

		this->updateFunction = updateFunction;

		node = ApplicationThreadManager::GetInstance()->AddThread(this);

	}

	ApplicationThread::~ApplicationThread() {



	}



	/**
	 *	Release Method
	 */
	void ApplicationThread::Release() {

		ApplicationThreadManager::GetInstance()->RemoveThread(node);

		Thread::Release();

	}



	/**
	 *	StartUpdate, Update, WaitUpdate Methods
	 */
	void ApplicationThread::StartUpdate() {

		mutex.lock();

		isFrameStart	= true;

		isFrameEnd		= false;

		mutex.unlock();

	}

	void ApplicationThread::Update() {

		while (true) {

			mutex.lock();

			if (Application::GetInstance()->GetState() != RUNNING_APPLICATION_STATE) {

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

	void ApplicationThread::WaitUpdate() {

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


/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Configuration
 */
#include <ING/Application/Configuration/Configuration.h>



 /**
  *	Include JobThread
  */
#include <ING/Job/Thread/Thread.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	JobSystem::JobSystem() {

		isRunning = false;
		threadCount = 1;

		Application::GetInstance()->GetConfiguration()->Add<unsigned int>("JobSystem::threadCount");

		Application::GetInstance()->GetConfiguration()->Set<unsigned int>("JobSystem::threadCount",1);

	}

	JobSystem::~JobSystem() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool JobSystem::Init() {

		RecreateThreads();

		return Square::Init();
	}

	bool JobSystem::Run() {

		RunThreads();

		return Square::Run();
	}

	bool JobSystem::Release() {

		DeleteThreads();

		return Square::Release();
	}



	/**
	 *	JobThreads Management Methods
	 */
	void JobSystem::RecreateThreads() {

		JoinThreads();

		CreateThreads();

	}

	void JobSystem::CreateThreads() {

		threadCount = Application::GetInstance()->GetConfiguration()->Get<int>("JobSystem::threadCount");

		threads.resize(threadCount);

		for (unsigned int i = 0; i < threadCount; ++i) {

			threads[i] = new JobThread();

		}

	}

	void JobSystem::RunThreads() {

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			threads[i]->Start();

		}

	}

	void JobSystem::JoinThreads() {

		this->isRunning = false;

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			threads[i]->Join();

		}

		threads.clear();

	}

	void JobSystem::DeleteThreads() {

		unsigned int currentThreadCount = threads.size();

		for (unsigned int i = 0; i < currentThreadCount; ++i) {

			delete threads[i];

		}

	}

}
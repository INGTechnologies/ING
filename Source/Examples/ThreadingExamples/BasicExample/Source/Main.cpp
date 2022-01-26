
/**
 *	Include IOStream
 */
#include <iostream>



 /**
  *	Include Application
  */
#include <ING/Application/Application.h>



  /**
   *	Include Thread And Thread Manager
   */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



   /**
	*	Include Event And Event Manager
	*/
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



	/**
	 *	Include Rendering
	 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



using namespace ING;



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();


	List<int>::Ref list = new List<int>();

	int firstElement = 5;

	list.Add(firstElement);


	/*
	while (true) {

		Thread* exThread = new Thread([](Thread* thread) {

			thread->WaitReady();

			ThreadManager::GetInstance()->RegisterThread(thread);

			std::cout << "new thread is running..." << std::endl;

			ThreadManager::GetInstance()->UnregisterThread(thread);

		});

		exThread->Start();

		exThread->Join();

	}
	*/


	system("pause");
	return 0;
}
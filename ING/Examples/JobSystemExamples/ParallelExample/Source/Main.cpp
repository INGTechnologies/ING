
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



 /**
  *	Include JobSystem
  */
#include <ING/Job/Job.h>
#include <ING/Job/CustomJob.h>
#include <ING/Job/CustomParallelJob.h>
#include <ING/Job/ParallelJob.h>
#include <ING/Job/System/System.h>



using namespace ING;



struct ExampleJob : public CustomJob<ExampleJob> {

	int a;

	void Execute() {

		for (unsigned int index = 0; index < 1000000000; ++index) {

			int b = 1 + 3;

		}

	};

};



struct ExampleParallelJob : public CustomParallelJob<ExampleParallelJob> {

	ExampleParallelJob(unsigned int threadCount) :
		CustomParallelJob<ExampleParallelJob>(threadCount)
	{



	}

	int a;

	void Execute(unsigned int index) {

		for (unsigned int i = 0; i < 1000000; ++i) {

			int b = 1 + 3;

		}

	};

};


#include <ctime>



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();





	
	//ExampleJob* job = new ExampleJob();
	ExampleParallelJob* job = new ExampleParallelJob(1000);

	unsigned int t = clock();

	job->SetQueue(1);

	job->a = 0;

	job->Schedule();

	job->Complete();

	job->Release();

	t = clock() - t;


	Debug::Log(String("Done In ") + String(t) + String("ms"));
	

	system("pause");
	return 0;
}
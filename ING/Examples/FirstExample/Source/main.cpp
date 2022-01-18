
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
#include <ING/Job/System/System.h>



using namespace ING;



struct ExampleJob : public CustomJob<ExampleJob> {

	int a;

	void Execute() {

		Debug::Log(a);

	};

};



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();



	for (int i = 0; i < 20; ++i) {

		ExampleJob* job = new ExampleJob();

		job->SetQueue(i);

		job->a = i;

		job->Schedule();

	}



	while (true) {}

	system("pause");
	return 0;
}
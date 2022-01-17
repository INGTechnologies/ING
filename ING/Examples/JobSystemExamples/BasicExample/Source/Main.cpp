
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



/**
 *	Include Application Configuration
 */
#include <ING/Application/Configuration/Configuration.h>



using namespace ING;



struct ExampleJob: public CustomJob<ExampleJob> {

	int a;

	List<Auto> list;

	void Execute() {

		Debug::Log(std::string("Example Job Executed"));

	};

};



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();


	
	ExampleJob* job = new ExampleJob();

	job->a = 5;

	job->Schedule();

	job->Complete();

	delete job;
	

	system("pause");
	return 0;
}

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
#include <ING/Debug/Debug.h>



using namespace ING;



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();



	//Create Id Generator
	IdGenerator generator;



	//Create Ids
	ui8		id8		= generator.GenUInt8();
	ui16	id16	= generator.GenUInt16();
	ui32	id32	= generator.GenUInt32();
	ui64	id64	= generator.GenUInt64();


	
	//Log Ids
	Debug::Log(id8);
	Debug::Log(id16);
	Debug::Log(id32);
	Debug::Log(id64);



	//Remove Ids
	generator.RemoveUInt8Id(id8);
	generator.RemoveUInt16Id(id16);
	generator.RemoveUInt32Id(id32);
	generator.RemoveUInt64Id(id64);



	system("pause");
	return 0;
}
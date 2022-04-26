
/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Thread
 */
#include <thread>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	System::System() {

		Debug::Log("Start Creating System");

		numberOfProcessors = std::thread::hardware_concurrency();

		Debug::Log("System Created");

	}

	System::~System() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool System::Init() {

		Debug::Log("Start Initializing System");

		Debug::Log("System Initialized");

		return true;
	}

	bool System::Run() {

		Debug::Log("Start Running System");

		return true;
	}

	bool System::Release() {

		Debug::Log("Start Releasing System");

		Debug::Log("Finished Releasing System");

		return Square::Release();
	}

}
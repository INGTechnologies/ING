
/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include Thread
 */
#include <thread>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	System::System() {

		numberOfProcessors = std::thread::hardware_concurrency();

	}

	System::~System() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool System::Init() {

		return true;
	}

	bool System::Run() {



		return true;
	}

	bool System::Release() {



		return Square::Release();
	}

}
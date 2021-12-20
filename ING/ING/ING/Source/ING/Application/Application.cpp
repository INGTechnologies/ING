
/**
 *	Include Header
 */
#include "Application.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Application::Application() {

		/**
		 *	Add Squares
		 */
		/* Core */
		AddSquare<Core>();

		/* Thread Managers */
		AddSquare<ThreadManager>();

		AddSquare<ApplicationThreadManager>();

		/* Event Managers */
		AddSquare<EventManager>();

		AddSquare<ApplicationEventManager>();

	}

	Application::~Application() {

		

	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Application::Init() {

		

		return Board<Application>::Init();
	}


	bool Application::Run() {

				

		return Board<Application>::Run();
	}


	bool Application::Release() {

		

		return Board<Application>::Release();
	}


}

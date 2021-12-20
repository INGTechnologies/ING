
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



/**
 *	Include Core
 */
#include <ING/Core/Core.h>



/**
 *	Include Thread Managers
 */
#include <ING/Thread/Manager/Manager.h>

#include <ING/Application/ThreadManager/ThreadManager.h>



/**
 *	Include Event Managers
 */
#include <ING/Event/Manager/Manager.h>

#include <ING/Application/EventManager/EventManager.h>



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


		Board<Application>::Init();

		return true;
	}


	bool Application::Run() {


		Board<Application>::Run();

		return true;
	}


	bool Application::Release() {


		Board<Application>::Release();

		return true;
	}


}


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
 *	Include Core
 */
#include <ING/Core/Core.h>



 /**
  *	Include Thread Managers
  */
#include <ING/Thread/Manager/Manager.h>

#include <ING/Application/ThreadManager/ThreadManager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>



/**
 *	Include Event Managers
 */
#include <ING/Event/Manager/Manager.h>

#include <ING/Application/EventManager/EventManager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include JobSystem
 */
#include <ING/Job/System/System.h>



/**
 *	Include ApplicationConfiguration
 */
#include <ING/Application/Configuration/Configuration.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Application::Application() {

		/**
		 *	Create Configuration
		 */
		configuration = new ApplicationConfiguration();



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

		/* Rendering Engine */
		AddSquare<Rendering::Engine>();

		/* Job System */
		AddSquare<JobSystem>();

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

		delete configuration;

		return Board<Application>::Release();
	}


}


/**
 *	Include Header
 */
#include "Manager.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationWindowManager::ApplicationWindowManager(IApplication* application) :
		application(application)
	{

		Configuration* configuration = application->GetConfiguration();

	}

	ApplicationWindowManager::~ApplicationWindowManager()
	{



	}



	/**
	 *	Release Methods
	 */
	void ApplicationWindowManager::Release()
	{

		delete this;

	}



	/**
	 *	Methods
	 */
	void ApplicationWindowManager::AddWindow		(IWindow* window) {

		name2WindowMap[window->GetName()] = window;

	}

	void ApplicationWindowManager::RemoveWindow		(IWindow* window) {

		name2WindowMap.erase(window->GetName());

	}
	
}
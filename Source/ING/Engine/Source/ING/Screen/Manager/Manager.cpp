
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
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ScreenManager::ScreenManager()
	{



	}

	ScreenManager::~ScreenManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ScreenManager::Init()
	{



		return true;
	}

	bool ScreenManager::Run()
	{



		return true;
	}

	bool ScreenManager::Release()
	{



		return true;
	}



	/**
	 *	Screen Management
	 */
	Screen* ScreenManager::mainScreen = nullptr;

	void ScreenManager::InitScreen(Screen* screen) {

		if (mainScreen != nullptr) return;

		mainScreen = screen;

	}

}

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



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ScreenManager::ScreenManager() :
		mainScreen(0)
	{

		Debug::Log("Start Creating ScreenManager");

		mainScreen = nullptr;

		Debug::Log("ScreenManager Created");

	}

	ScreenManager::~ScreenManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ScreenManager::Init()
	{

		Debug::Log("Start Initializing ScreenManager");

		Debug::Log("ScreenManager Initialized");

		return true;
	}

	bool ScreenManager::Run()
	{

		Debug::Log("Start Running ScreenManager");

		return true;
	}

	bool ScreenManager::Release()
	{

		Debug::Log("Start Releasing ScreenManager");

		delete this;

		Debug::Log("Finished Releasing ScreenManager");

		return true;
	}



	/**
	 *	Methods
	 */
	void					ScreenManager::InitScreen	(Screen* screen) {

		if (mainScreen != nullptr) return;

		mainScreen = screen;

	}

}
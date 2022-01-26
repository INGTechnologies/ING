
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
 *	Include Window
 */
#include <ING/Window/Window.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	WindowManager::WindowManager()
	{

		

	}

	WindowManager::~WindowManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool WindowManager::Init()
	{



		return true;
	}

	bool WindowManager::Run()
	{



		return true;
	}

	bool WindowManager::Release()
	{

		windowMap.clear();

		return true;
	}



	/**
	 *	Window Management
	 */
	Window* WindowManager::mainWindow = nullptr;

	void	WindowManager::AddWindow	(Window* window)	{

		HWND handle = window->GetHandle();

		if (mainWindow == nullptr) {

			mainWindow = window;

			window->isMain = true;

		}

		windowMap[handle] = window;

	}

	void	WindowManager::RemoveWindow	(Window* window)	{

		HWND handle = window->GetHandle();

		windowMap.erase(handle);

	}

	Window* WindowManager::GetWindow	(HWND handle)		{

		return windowMap[handle];

	}

}
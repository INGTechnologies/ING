
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
	WindowManager::WindowManager()
	{

		if (!Application::GetInstance()->GetConfiguration()->Exist("ING::Application::autoCreateWindow")) {

			Application::GetInstance()->GetConfiguration()->Add<bool>("ING::Application::autoCreateWindow");

			Application::GetInstance()->GetConfiguration()->Set<bool>("ING::Application::autoCreateWindow", true);

		}

	}

	WindowManager::~WindowManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool WindowManager::Init()
	{

		autoCreateWindow = Application::GetInstance()->GetConfiguration()->Get<bool>("ING::Application::autoCreateWindow");

		if (autoCreateWindow) {

			new Window(defaultDesc);

		}

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

		if (windowMap.find(handle) == windowMap.end()) return nullptr;

		return windowMap[handle];

	}

	bool	WindowManager::CheckMessage() {

		bool result = false;

		MSG msg = { 0 };

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			result = true;

		}

		unsigned int windowCount = windowMap.size();

		if (autoCreateWindow && windowCount == 0) {

			Application::GetInstance()->Shutdown();

		}

		return result;

	}

}
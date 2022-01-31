
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



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	WindowManager::WindowManager()
	{

		APPLICATION_CONFIG_PROP(unsigned int, "ING::WindowManager::startupWindowCount", 1);

		APPLICATION_CONFIG_PROP(bool, "ING::WindowManager::autoShutdown", true);

		APPLICATION_CONFIG_PROP(bool, "ING::WindowManager::showConsoleWindow", false);

	}

	WindowManager::~WindowManager()
	{



	}

	

	/**
	 *	Init, Run, Release Methods
	 */
	bool WindowManager::Init()
	{

		startupWindowCount	= Application::GetInstance()->GetConfiguration()->Get<unsigned int>("ING::WindowManager::startupWindowCount");

		autoShutdown		= Application::GetInstance()->GetConfiguration()->Get<bool>("ING::WindowManager::autoShutdown");

		showConsoleWindow	= Application::GetInstance()->GetConfiguration()->Get<bool>("ING::WindowManager::showConsoleWindow");



		/* Create Console Window */
		consoleWindow = new Window();

		consoleWindow->handle = ::GetConsoleWindow();

		AddWindow(consoleWindow);

		RECT rect;
		if (GetWindowRect(consoleWindow->handle, &rect))
		{
			ScreenDesc screenDesc;

			screenDesc.clientWidth		= rect.right - rect.left;
			screenDesc.clientHeight		= rect.bottom - rect.top;

			screenDesc.initSwapChain	= false;

			consoleWindow->screen = new Screen(consoleWindow, screenDesc);
		}

		if (showConsoleWindow) {

			consoleWindow->Show();

		}
		else {

			consoleWindow->Hide();

		}



		/* Create Startup Window */
		for (unsigned int i = 0; i < startupWindowCount; ++i) {

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

		consoleWindow->Release();

		idGenerator.ClearIds();

		windowMap.clear();

		return true;
	}



	/**
	 *	Window Management
	 */
	void			WindowManager::AddWindow	(Window* window)	{

		HWND handle = window->GetHandle();

		if (mainWindow == nullptr && window != consoleWindow) {

			mainWindow = window;

			window->isMain = true;

		}

		windowMap[handle] = window;

	}

	void			WindowManager::RemoveWindow	(Window* window)	{

		HWND handle = window->GetHandle();

		windowMap.erase(handle);

	}

	Window*			WindowManager::GetWindow	(HWND handle)		{

		if (windowMap.find(handle) == windowMap.end()) return nullptr;

		return windowMap[handle];

	}

	bool			WindowManager::CheckMessage() {

		bool result = false;

		MSG msg = { 0 };

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			result = true;

		}

		return result;

	}

	ui16			WindowManager::NewClassId() {

		return idGenerator.GenUInt16();

	}

	void			WindowManager::RemoveClassId(ui16 id) {

		idGenerator.RemoveUInt16Id(id);

	}

}
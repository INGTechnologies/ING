
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

		if (!Application::GetInstance()->GetConfiguration()->Exist("ING::WindowManager::autoCreateWindow")) {

			Application::GetInstance()->GetConfiguration()->Add<unsigned int>("ING::WindowManager::startupWindowCount");

			Application::GetInstance()->GetConfiguration()->Set<unsigned int>("ING::WindowManager::startupWindowCount", 1);

		}

		if (!Application::GetInstance()->GetConfiguration()->Exist("ING::WindowManager::autoShutdown")) {

			Application::GetInstance()->GetConfiguration()->Add<unsigned int>("ING::WindowManager::autoShutdown");

			Application::GetInstance()->GetConfiguration()->Set<bool>("ING::WindowManager::autoShutdown", true);

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

		startupWindowCount	= Application::GetInstance()->GetConfiguration()->Get<unsigned int>("ING::WindowManager::startupWindowCount");

		autoShutdown		= Application::GetInstance()->GetConfiguration()->Get<bool>("ING::WindowManager::autoShutdown");

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

		idGenerator.ClearIds();

		windowMap.clear();

		return true;
	}



	/**
	 *	Window Management
	 */
	Window*			WindowManager::mainWindow = nullptr;

	void			WindowManager::AddWindow	(Window* window)	{

		HWND handle = window->GetHandle();

		if (mainWindow == nullptr) {

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

	std::wstring	WindowManager::NewClassId() {

		return WString(idGenerator.GenUInt16());

	}

	void			WindowManager::RemoveClassId(std::wstring id) {



	}

}
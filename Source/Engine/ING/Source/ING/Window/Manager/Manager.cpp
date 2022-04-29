
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
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	WindowManager::WindowManager() : 
		consoleWindow(0)
	{

		Debug::Log("Start Creating WindowManager");

		ING_ENGINE_CONFIG_PROP(unsigned int, "ING.WindowManager.startupWindowCount", 1);

		ING_ENGINE_CONFIG_PROP(bool, "ING.WindowManager.autoShutdown", true);

		ING_ENGINE_CONFIG_PROP(bool, "ING.WindowManager.showConsoleWindow", false);

		ING_ENGINE_CONFIG_PROP(std::string, "ING.WindowManager.consoleWindowTitle", "Console");

		ING_ENGINE_CONFIG_PROP(std::string, "ING.WindowManager.startupWindowTitle", "New Window");

		Debug::Log("WindowManager Created");

	}

	WindowManager::~WindowManager()
	{



	}

	

	/**
	 *	Init, Run, Release Methods
	 */
	bool WindowManager::Init()
	{

		Debug::Log("Start Initializing WindowManager");

		showConsoleWindow	= Engine::GetInstance()->GetConfiguration()->Get<bool>("ING.WindowManager.showConsoleWindow");

		consoleWindowTitle  = ToWString(Engine::GetInstance()->GetConfiguration()->Get<std::string>("ING.WindowManager.consoleWindowTitle"));



		/* Create Console Window */
		consoleWindow = IWindow::Create();

		consoleWindow->handle = ::GetConsoleWindow();

		AddWindow(consoleWindow);

		RECT rect;
		if (GetWindowRect((HWND)consoleWindow->handle, &rect))
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

		consoleWindow->desc.title = consoleWindowTitle;

		consoleWindow->SetTitle(consoleWindowTitle);

		Debug::Log("WindowManager Initialized");

		return true;
	}

	bool WindowManager::Run()
	{

		Debug::Log("Start Running WindowManager");

		return true;
	}

	bool WindowManager::Release()
	{

		Debug::Log("Start Releasing WindowManager");

		consoleWindow->Release();

		idGenerator.ClearIds();

		windowMap.clear();

		delete this;

		Debug::Log("Finished Releasing WindowManager");

		return true;
	}



	/**
	 *	Window Management
	 */
	void			WindowManager::AddWindow	(IWindow* window)	{

		void* handle = window->GetHandle();

		windowMap[handle] = window;

	}

	void			WindowManager::RemoveWindow	(IWindow* window)	{

		void* handle = window->GetHandle();

		windowMap.erase(handle);

	}

	IWindow*		WindowManager::GetWindow	(void* handle)		{

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
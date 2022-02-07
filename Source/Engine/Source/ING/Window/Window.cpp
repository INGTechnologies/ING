
/**
 *	Include Header
 */
#include "Window.h"



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
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Events
 */
/* Destroy */
#include <ING/Window/Event/Destroy/Destroy.h>

/* Key Events */
#include <ING/Window/Event/Key/Down/Down.h>
#include <ING/Window/Event/Key/Up/Up.h>

/* Mouse Events */
#include <ING/Window/Event/Mouse/Button/Down/Down.h>
#include <ING/Window/Event/Mouse/Button/Up/Up.h>
#include <ING/Window/Event/Mouse/Move/Move.h>

/* Resize Events */
#include <ING/Window/Event/Resize/Resize.h>



namespace ING {

	/**
	 *	WndProc
	 */
	LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{

		ING::Window* window = ING::WindowManager::GetInstance()->GetWindow(hwnd);



		switch (msg)
		{
		case WM_CREATE:
		{

			break;
		}

		case WM_DESTROY:
		{
			window->GetEvent("DESTROY")->Execute();

			window->Shutdown();

			::PostQuitMessage(0);
			break;
		}
		case WM_SIZE:
		{

			if (!window->IsResizing()) {

				ING::WindowResizeEvent* event = (ING::WindowResizeEvent*)window->GetEvent("RESIZE");

				event->newWidth = LOWORD(lparam);
				event->newHeight = HIWORD(lparam);

				event->Execute();

			}

			break;
		}
		case WM_ENTERSIZEMOVE:

			window->isResizing = true;

			break;
		case WM_EXITSIZEMOVE:

			window->isResizing = false;

			break;
		case WM_MOUSEMOVE:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_MBUTTONDOWN:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_LBUTTONUP:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_MBUTTONUP:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_RBUTTONUP:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_KEYDOWN:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_KEYUP:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}
		case WM_MOUSELEAVE:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
			break;
		}

		default:
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
		}

		return NULL;
	}



	/**
	 *	Constructors And Destructor
	 */
	Window::Window() :
		isMain(false), handle(NULL)
	{

		InitEvents();

	}

	Window::Window(WindowDesc desc) :
		isMain(false), handle(NULL)
	{

		InitEvents();

		InitWithDesc(desc);

	}

	Window::~Window() 
	{



	}



	/**
	 *	InitWithDesc, InitEvents, Release Methods
	 */
	void Window::InitWithDesc(WindowDesc desc) {

		classId = WindowManager::GetInstance()->NewClassId();

		std::wstring className = WString(L"INGWindowClass_") + WString(classId);

		/* Create Class */
		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = className.c_str();
		wc.lpszMenuName = L"";
		wc.style = NULL;
		wc.lpfnWndProc = &WndProc;


		if (!::RegisterClassEx(&wc))
			return;

		/* Create Window Ex */
		handle = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, className.c_str(), desc.title,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, desc.clientWidth, desc.clientHeight,
			NULL, NULL, NULL, this);


		WindowManager::GetInstance()->AddWindow(this);


		if (desc.show) {

			Show();

		}
		else {

			Hide();

		}


		::UpdateWindow(handle);



		/* Create Screen */
		ScreenDesc screenDesc;

		screenDesc.clientWidth = desc.clientWidth;
		screenDesc.clientHeight = desc.clientHeight;

		screen = new Screen(this,screenDesc);

	}

	void Window::InitEvents() {

		/**
		 *	Destroy Event
		 */
		AddEvent( new WindowDestroyEvent());



		/**
		 *	Key Events
		 */
		AddEvent( new WindowKeyDownEvent());

		AddEvent( new WindowKeyUpEvent());



		/**
		 *	Mouse Events
		 */
		AddEvent( new WindowMouseBtnDownEvent());

		AddEvent( new WindowMouseBtnUpEvent());

		AddEvent( new WindowMouseMoveEvent());



		/**
		 *	Mouse Events
		 */
		AddEvent( new WindowResizeEvent() );

	}

	void Window::Release() 
	{
		if(screen != nullptr)
			screen->Release();

		WindowManager::GetInstance()->RemoveClassId(classId);

		WindowManager::GetInstance()->RemoveWindow(this);

		RELEASE_EVENT_STORAGE;

		delete this;

	}

	void Window::Shutdown() {

		Release();

	}



	/**
	 *	Methods
	 */
	void			Window::Show() {

		::ShowWindow(handle, SW_SHOW);

	}

	void			Window::Hide() {

		::ShowWindow(handle, SW_HIDE);

	}

	void			Window::SetTitle(std::wstring title) {

		desc.title = title.c_str();

		SetWindowTextW(handle, title.c_str());

	}

	std::wstring	Window::GetTitle() {

		return WString(desc.title);

	}



	/**
	 *	Event Management
	 */
	List<Event*>::Node*		Window::AddEvent(Event* event) {

		((WindowEvent*)event)->window = this;

		return EventStorage::AddEvent(event);

	}

}
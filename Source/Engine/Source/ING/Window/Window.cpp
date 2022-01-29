
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
 *	WndProc
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
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
		window->Shutdown();
		::PostQuitMessage(0);
		break;
	}
	case WM_SIZE:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
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





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Window::Window() :
		isMain(false), handle(NULL)
	{

		//WindowDesc desc;

		//InitWithDesc(desc);

	}

	Window::Window(WindowDesc desc) :
		isMain(false), handle(NULL)
	{

		InitWithDesc(desc);

	}

	Window::~Window() 
	{



	}



	/**
	 *	InitWithDesc, Release Methods
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

	void Window::Release() 
	{

		screen->Release();

		WindowManager::GetInstance()->RemoveClassId(classId);

		WindowManager::GetInstance()->RemoveWindow(this);

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

}
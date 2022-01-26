#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Include Windows
 */
#include <Windows.h>



namespace ING {

	class Window;

	class ING_API WindowManager :
		public Singleton<WindowManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		WindowManager();
		~WindowManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();



		/**
		 *	Window Management
		 */
	private:
		static	Window* mainWindow;
		std::map<HWND, Window*> windowMap;

	public:
		static	Window* GetMainWindow	() { return mainWindow; }

				void	AddWindow		(Window* window);

				void	RemoveWindow	(Window* window);

				Window*	GetWindow		(HWND handle);

	};

}
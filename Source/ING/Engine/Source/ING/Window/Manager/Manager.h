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



/**
 *	Include Window Desc
 */
#include <ING/Window/Desc/Desc.h>



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
		static	Window*			mainWindow;

		std::map<HWND, Window*> windowMap;

		unsigned int			startupWindowCount;

		bool					autoShutdown;

		WindowDesc				defaultDesc;

		IdGenerator				idGenerator;

	public:
		Window*							GetMainWindow			() { return mainWindow; }

		std::map<HWND, Window*>&		GetWindowMap			() { return windowMap; }

		unsigned int					GetStartupWindowCount	() { return startupWindowCount; }

		bool							IsAutoShutdown			() { return autoShutdown; }

		void							AddWindow				(Window* window);

		void							RemoveWindow			(Window* window);

		Window*							GetWindow				(HWND handle);

		WindowDesc						GetDefaultDesc			() { return defaultDesc; }

		void							SetDefaultDesc			(WindowDesc desc) { defaultDesc = desc; }

		bool							CheckMessage			();

		std::wstring					NewClassId				();

		void							RemoveClassId			(std::wstring id);

	};

}
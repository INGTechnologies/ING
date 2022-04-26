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

	class IWindow;

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
		 *	IWindow Management
		 */
	private:
		IWindow*						consoleWindow;

		std::map<void*, IWindow*>		windowMap;

		bool							showConsoleWindow;

		WindowDesc						defaultDesc;

		IdGenerator						idGenerator;

		std::wstring					consoleWindowTitle;

	public:
		IWindow*						GetConsoleWindow		() { return consoleWindow; }

		std::map<void*, IWindow*>&		GetWindowMap			() { return windowMap; }

		bool							IsShowConsoleWindow		() { return showConsoleWindow; }

		void							AddWindow				(IWindow* window);

		void							RemoveWindow			(IWindow* window);

		IWindow*						GetWindow				(void* handle);

		WindowDesc						GetDefaultDesc			() { return defaultDesc; }

		void							SetDefaultDesc			(WindowDesc desc) { defaultDesc = desc; }

		bool							CheckMessage			();

		ui16							NewClassId				();

		void							RemoveClassId			(ui16 id);

		const std::wstring&				GetConsoleWindowTitle	() { return consoleWindowTitle; }

	};

}
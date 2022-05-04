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
 *	Include Window Manager
 */
#include <ING/Window/Manager/Manager.h>



/**
 *	Include Windows
 */
#include <Windows.h>



/**
 *	Include Map
 */
#include <map>



/**
 *	Include WindowDesc
 */
#include <ING/Window/Desc/Desc.h>



/**
 *	Include EventStorage
 */
#include <ING/Event/Storage/Storage.h>



/**
 *	Include Window Style
 */
#include <ING/Window/Style/Style.h>



namespace ING {

	class Screen;

	class Event;

	class WindowEvent;

	class ApplicationWindowSystem;



	class ING_API IWindow :
		public EventStorage
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class WindowManager;



		/**
		 *	Constructors And Destructor
		 */
	protected:
		IWindow		(ApplicationWindowSystem* system);
		IWindow		(const WindowDesc& desc, ApplicationWindowSystem* system);
		~IWindow	();



		/**
		 *	Create, InitWithDesc, InitEvents, Release Methods
		 */
	protected:
		virtual void InitWithDesc(const WindowDesc& desc);
				void InitEvents();
		
	public:
		static IWindow* Create(ApplicationWindowSystem* system);
		static IWindow* Create(const WindowDesc& desc, ApplicationWindowSystem* system);
		virtual void Release();



		/**
		 *	Properties
		 */
	protected:
		void*		handle;
		WindowDesc	desc;

		ui16		classId;

		Screen*		screen;

		bool		isResizing;

		ApplicationWindowSystem* system;

	public:
		void*		GetHandle	() { return handle; }

		const WindowDesc& GetDesc	() { return desc; }

		const String&	GetName		() { return desc.name; }

		Screen*		GetScreen	() { return screen; }

		bool		IsResizing	() { return isResizing; }

		ApplicationWindowSystem* GetSystem() { return system; }



		/**
		 *	Methods
		 */
	public:
		virtual void	Show();

		virtual void	Hide();

		virtual void	Focus();


		/* Title */
		virtual void	SetTitle(const WString& title);

		virtual void	SetTitle(const wchar_t* title) {

			SetTitle(WString(title));

		}

		WString	GetTitle();


		/* Icon */
		virtual void	SetIconFromFile(const WString& path);


		/* Style */
		virtual unsigned int GetStyle();
		virtual void	SetStyle(unsigned int styleFlag);
		virtual unsigned int GetExStyle();
		virtual void	SetExStyle(unsigned int styleFlag);



	protected:
		void			CreateScreen();



		/**
		 *	Event Management
		 */
		virtual List<Event*>::Node*		AddEvent(Event* event) override;

	};

}
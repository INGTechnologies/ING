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



namespace ING {

	class Screen;

	class Event;

	class WindowEvent;



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
		IWindow		();
		IWindow		(const WindowDesc& desc);
		~IWindow	();



		/**
		 *	Create, InitWithDesc, InitEvents, Release Methods
		 */
	protected:
		virtual void InitWithDesc(const WindowDesc& desc);
				void InitEvents();
		
	public:
		static IWindow* Create();
		static IWindow* Create(const WindowDesc& desc);
		virtual void Release();

				void Shutdown();



		/**
		 *	Properties
		 */
	protected:
		void*		handle;
		WindowDesc	desc;

		ui16		classId;

		Screen*		screen;

		bool		isResizing;

	public:
		void*		GetHandle	() { return handle; }

		WindowDesc	GetDesc		() { return desc; }

		const std::string&	GetName		() { return desc.name; }

		Screen*		GetScreen	() { return screen; }

		bool		IsResizing	() { return isResizing; }



		/**
		 *	Methods
		 */
	public:
		virtual void	Show();

		virtual void	Hide();

		virtual void	Focus();


		/* Title */
		virtual void	SetTitle(const std::wstring& title);

		virtual void	SetTitle(const wchar_t* title) {

			SetTitle(WString(title));

		}

		std::wstring	GetTitle();


	protected:
		void			CreateScreen();



		/**
		 *	Event Management
		 */
		virtual List<Event*>::Node*		AddEvent(Event* event) override;

	};

}
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



namespace ING {

	class Screen;

	class Event;

	class WindowEvent;



	class ING_API Window
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class WindowManager;



		/**
		 *	Constructors And Destructor
		 */
	private:
		Window();

	public:
		Window(WindowDesc desc);
		~Window();



		/**
		 *	InitWithDesc, InitEvents, Release Methods
		 */
	private:
		virtual void InitWithDesc(WindowDesc desc);

				void InitEvents();
		
	public:
		virtual void Release();

				void Shutdown();



		/**
		 *	Properties
		 */
	private:
		bool		isMain;
		HWND		handle;
		WindowDesc	desc;

		ui16		classId;

		Screen*		screen;

	public:
		bool		IsMain		() { return isMain; }

		HWND		GetHandle	() { return handle; }

		WindowDesc	GetDesc		() { return desc; }

		Screen*		GetScreen	() { return screen; }



		/**
		 *	Methods
		 */
	public:
		void			Show();

		void			Hide();


		/* Title */
		void			SetTitle(std::wstring title);

		void			SetTitle(const wchar_t* title) {

			SetTitle(WString(title));

		}

		std::wstring	GetTitle();



		/**
		 *	Events
		 */
	private:
		List<Event*> eventList;

		std::map<std::string, Event*> eventMap;

	public:
		const List<Event*>&		GetEventList() { return eventList; }

		Event*					GetEvent(std::string name);

		List<Event*>::Node*		AddEvent(Event* event);

		template<class T>
		List<Event*>::Node* AddEvent() {

			T* event = new T();

			return AddEvent(event);

		}

		void					RemoveEvent(List<Event*>::Node* eventNode);

	};

}
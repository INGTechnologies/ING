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
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



namespace ING {

	class ING_API WindowEvent : public Event {

		/**
		 *	Friend Classes
		 */
	public:
		friend class IWindow;



		/**
		 *	Constructors And Destructor
		 */
	public:
		WindowEvent() : window(0) {



		}

		~WindowEvent() {



		}



		/**
		 *	Window
		 */
	private:
		IWindow* window;

	public:
		IWindow* GetWindow() { return window; }

	};


}
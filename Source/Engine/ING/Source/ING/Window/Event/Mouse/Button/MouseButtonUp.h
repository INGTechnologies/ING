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
 *	Include Window Event
 */
#include <ING/Window/Event/Event.h>



namespace ING {

	class ING_API WindowMouseBtnUpEvent : public WindowEvent {

		/**
		 *	Constructors And Destructor
		 */
	public:
		WindowMouseBtnUpEvent();

		~WindowMouseBtnUpEvent();



		/**
		 *	Name
		 */
	public:
		virtual String GetName() override;

	};


}
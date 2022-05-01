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



namespace ING {

	class ING_API EngineEndFrameUpdateEvent : public Event {

		/**
		 *	Constructors And Destructor
		 */
	public:
		EngineEndFrameUpdateEvent();

		~EngineEndFrameUpdateEvent();



		/**
		 *	Name
		 */
	public:
		virtual String GetName() override;

	};


}
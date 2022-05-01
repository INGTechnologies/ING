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



namespace ING {

	class Event;



	class ING_API EventStorage
	{
		/**
		 *	Constructors And Destructor
		 */
	public:
		EventStorage();
		~EventStorage();



		/**
		 *	Event Management
		 */
	protected:
		List<Event*> eventList;

		std::map<String, Event*> eventMap;

	public:
		const List<Event*>&			GetEventList() { return eventList; }

		Event*						GetEvent(const String& name);

		virtual List<Event*>::Node*	AddEvent(Event* event);

		void						RemoveEvent(List<Event*>::Node* eventNode);

	};


	/**
	 *	Define Macros
	 */
#define RELEASE_EVENT_STORAGE()\
	eventList.Foreach([](Event*& e) {\
		\
		e->Release();\
		\
		});\
	\
	eventMap.clear();\

}
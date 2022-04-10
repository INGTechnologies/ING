
/**
 *	Include Header
 */
#include "Storage.h"



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EventStorage::EventStorage()
	{



	}

	EventStorage::~EventStorage()
	{



	}



	/**
	 *	Event Management
	 */
	Event*					EventStorage::GetEvent(const std::string& name) {

		return eventMap[name];

	}

	List<Event*>::Node*		EventStorage::AddEvent(Event* event) {

		eventMap[event->GetName()] = event;

		return eventList.Add(event);

	}

	void					EventStorage::RemoveEvent(List<Event*>::Node* eventNode) {

		eventMap.erase(((Event*)(eventNode->pValue))->GetName());

		eventList.Remove(eventNode);

	}

}
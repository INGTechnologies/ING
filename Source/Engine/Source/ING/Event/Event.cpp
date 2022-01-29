
/**
 *	Include Header
 */
#include "Event.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Event::Event() {



	}

	Event::~Event() {



	}



	/*
	 *	Listeners
	 */
	List<Event::Listener>::Node*	Event::AddListener(Listener listener) {

		return listenerList.Add(listener);

	}

	void							Event::RemoveListener(List<Event::Listener>::Node* listenerNode) {

		listenerList.Remove(listenerNode);

	}



	/**
	 *	Execute
	 */
	void Event::Execute() {

		List<Event::Listener>::Node* node = listenerList.GetHeadNode();

		while (node != nullptr) {

			(*((Listener*)node->pValue))(this);

			node = node->next;

		}

	}



	/**
	 *	Release Method
	 */
	void Event::Release() {

		delete this;

	}

}
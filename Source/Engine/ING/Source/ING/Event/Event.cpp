
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
	Event::Event() : currentNode(0) {



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

	void							Event::RemoveCurrentListener() {

		listenerList.Remove(currentNode);

	}



	/**
	 *	Execute
	 */
	void Event::Execute() {

		List<Event::Listener>::Node* node = listenerList.GetHeadNode();

		while (node != nullptr) {

			List<Event::Listener>::Node* nextNode = node->next;

			currentNode = node;

			(*((Listener*)node->pValue))(this);

			node = nextNode;

		}

	}



	/**
	 *	Release Method
	 */
	void Event::Release() {

		delete this;

	}

}

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
	List<Event::Listener>::Node*	Event::AddListener(Listener listener, void* owner) {

		List<Event::Listener>::Node* result = listenerList.Add(listener);

		ownerMap[result] = owner;

		return result;
	}

	List<Event::Listener>::Node* Event::AddListener(Listener listener) {

		List<Event::Listener>::Node* result = listenerList.Add(listener);

		return result;
	}

	void							Event::RemoveListener(List<Event::Listener>::Node* listenerNode) {

		if (IsHasOwner(listenerNode)) {

			ownerMap.erase(listenerNode);

		}

		listenerList.Remove(listenerNode);

	}

	void							Event::RemoveCurrentListener() {

		listenerList.Remove(currentNode);

	}

	void*							Event::GetOwner(List<Listener>::Node* node) {

		if (ownerMap.find(node) == ownerMap.end()) return 0;

		return ownerMap[node];

	}

	void*							Event::GetCurrentOwner() {

		return GetOwner(currentNode);

	}

	void							Event::SetOwner(List<Listener>::Node* node, void* owner) {

		ownerMap[node] = owner;

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
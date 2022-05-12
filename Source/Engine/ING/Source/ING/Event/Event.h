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



namespace ING {

	class ING_API Event {

		/**
		 *	Nested Types
		 */
	public:
		typedef void (*Listener)(Event* e);



		/**
		 *	Constructors And Destructor
		 */
	public:
		Event();
		~Event();



		/**
		 *	Name
		 */
	public:
		virtual String GetName() { return "DEFAULT_EVENT"; };



		/*
		 *	Listeners
		 */
	private:
		List<Listener>			listenerList;

		List<Listener>::Node*	currentNode;

		std::unordered_map<List<Listener>::Node*, void*> ownerMap;

	public:
		const List<Listener>&	GetListenerList		() { return listenerList; }

		List<Listener>::Node*	AddListener			(Listener listener, void* owner);
		List<Listener>::Node*	AddListener			(Listener listener);

		List<Listener>::Node*	GetCurrentListenerNode	() { return currentNode; }

		void					RemoveListener		(List<Event::Listener>::Node* listenerNode);

		void					RemoveCurrentListener();

		void*					GetOwner			(List<Listener>::Node* node);
		void*					GetCurrentOwner		();
		bool					IsHasOwner			(List<Listener>::Node* node) { return ownerMap.find(node) != ownerMap.end(); }
		void					SetOwner			(List<Listener>::Node* node, void* owner);



		/**
		 *	Execute
		 */
	public:
		virtual void Execute();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();

	};


}
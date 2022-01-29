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
		typedef void (*Listener)(Event*);



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
		virtual std::string GetName() { return "DEFAULT_EVENT"; };



		/*
		 *	Listeners
		 */
	private:
		List<Listener> listenerList;

	public:
		const List<Listener>&	GetListenerList		() { return listenerList; }

		List<Listener>::Node*	AddListener			(Listener listener);

		void					RemoveListener		(List<Event::Listener>::Node* listenerNode);



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
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

	namespace UI {

		class Element;



		class ING_API Node
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Node(Element* element);
			~Node();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Element*	element;

			List<Node*> childList;

			List<Node*>::Node* nodeInParentChildList;

			Node*		parentNode;

		public:
			Element*	GetElement() { return element; }



			/**
			 *	Methods
			 */
		public:
			void		AddChild	(Node* child);
			void		RemoveChild	(Node* child);

		};

	}

}
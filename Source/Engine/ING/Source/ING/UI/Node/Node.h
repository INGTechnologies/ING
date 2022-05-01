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

		class IElement;



		class ING_API Node
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Node(IElement* element);
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
			IElement*	element;

			List<Node*> childList;

			List<Node*>::Node* nodeInParentChildList;

			Node*		parent;

		public:
			IElement*	GetElement	() { return element; }

			Node*		GetParent	() { return parent; }



			/**
			 *	Methods
			 */
		public:
			void			AddChild	(Node* child);
			void			RemoveChild	(Node* child);

			virtual void	Start();

			virtual void	PreUpdate();
			virtual void	Update();
			virtual void	LateUpdate();

			virtual void	PreRender();
			virtual void	Render();
			virtual void	LateRender();

		};

	}

}
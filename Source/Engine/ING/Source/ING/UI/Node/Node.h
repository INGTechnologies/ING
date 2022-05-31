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



/**
 *	Include Reflection
 */
#include <ING/Reflection/Type/Type.h>
#include <ING/Reflection/Namespace/Namespace.h>
#include <ING/Reflection/Object/Object.h>
#include <ING/Reflection/Object/Function/Function.h>
#include <ING/Reflection/Context/Context.h>
#include <ING/Reflection/Class/Class.h>

using namespace ING::Reflection;



namespace ING {

	namespace UI {

		class C_Element;



		class ING_API Node
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Node(C_Element* element);
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
			C_Element*	element;

			List<Node*> childList;

			List<Node*>::Node* nodeInParentChildList;

			Node*		parent;

		public:
			C_Element*	GetElement	() { return element; }

			const List<Node*>& GetChildList() { return childList; }

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

			virtual void	Resize();

		};

	}

}
#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



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

	namespace Editor {

		class PLUGIN_API(ING_EDITOR) LayoutNode
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			LayoutNode	();
			~LayoutNode	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			List<LayoutNode*>	childList;

			List<LayoutNode*>::Node* nodeInParentChildList;

			LayoutNode*			parent;

		public:
			const List<LayoutNode*>& GetChildList() { return childList; }

			LayoutNode*			GetParent	() { return parent; }



			/**
			 *	Methods
			 */
		public:
			void				AddChild	(LayoutNode* child);
			void				RemoveChild	(LayoutNode* child);

		};

	}

}
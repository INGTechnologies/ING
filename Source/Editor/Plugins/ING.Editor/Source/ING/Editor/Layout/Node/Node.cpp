
/**
 *	Include Header
 */
#include "Node.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING { 

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		LayoutNode::LayoutNode():
			nodeInParentChildList(0),
			parent(0)
		{



		}

		LayoutNode::~LayoutNode()
		{



		}



		/**
		 *	Release Methods
		 */
		void LayoutNode::Release() {

			if(parent != 0)
				parent->RemoveChild(this);

			for (auto item = childList.begin(); item != childList.end();) {

				auto nextItem = item.node->next;

				(*(item.node->pValue))->Release();

				item = nextItem;

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void LayoutNode::AddChild(LayoutNode* child) {

			childList.Add(child);

			child->parent = this;

		}

		void LayoutNode::RemoveChild(LayoutNode* child) {

			childList.Remove(child->nodeInParentChildList);

			child->parent = 0;

		}

	}

}
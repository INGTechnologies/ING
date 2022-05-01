
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



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



namespace ING { 

	namespace UI {

		/**
		 *	Constructors And Destructor
		 */
		Node::Node(Element* element):
			element(element),
			nodeInParentChildList(0),
			parentNode(0)
		{



		}

		Node::~Node()
		{



		}



		/**
		 *	Release Methods
		 */
		void Node::Release() {

			for (auto item = childList.begin(); item != childList.end();) {

				item.node->As<Node*>()->GetElement()->Release();

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void Node::AddChild(Node* child) {

			child->nodeInParentChildList = childList.Add(child);

			child->parentNode = this;

		}

		void Node::RemoveChild(Node* child) {

			childList.Remove(nodeInParentChildList);

			child->nodeInParentChildList = 0;

			child->parentNode = 0;

		}

	}

}
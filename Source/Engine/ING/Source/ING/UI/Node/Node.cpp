
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
		Node::Node(IElement* element):
			element(element),
			nodeInParentChildList(0),
			parent(0)
		{



		}

		Node::~Node()
		{



		}



		/**
		 *	Release Methods
		 */
		void Node::Release() {

			if(parent != 0)
				parent->RemoveChild(this);

			for (auto item = childList.begin(); item != childList.end();) {

				auto nextItem = item.node->next;

				(*(item.node->pValue))->GetElement()->Release();

				item = nextItem;

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void Node::AddChild(Node* child) {

			child->nodeInParentChildList = childList.Add(child);

			child->parent = this;

		}

		void Node::RemoveChild(Node* child) {

			childList.Remove(child->nodeInParentChildList);

			child->nodeInParentChildList = 0;

			child->parent = 0;

		}

		void Node::Start() {

			for (auto child : childList) {

				child->GetElement()->Start();

			}

		}

		void Node::PreUpdate() {

			for (auto child : childList) {

				child->GetElement()->PreUpdate();

			}

		}

		void Node::Update() {

			for (auto child : childList) {

				child->GetElement()->Update();

			}

		}

		void Node::LateUpdate() {

			for (auto child : childList) {

				child->GetElement()->LateUpdate();

			}

		}

		void Node::PreRender() {

			for (auto child : childList) {

				child->GetElement()->PreRender();

			}

		}

		void Node::Render() {

			for (auto child : childList) {

				child->GetElement()->Render();

			}

		}

		void Node::LateRender() {

			for (auto child : childList) {

				child->GetElement()->LateRender();

			}

		}

		void Node::Resize() {

			for (auto child : childList) {

				child->GetElement()->Resize();

			}

		}

	}

}
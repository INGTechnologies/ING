
/**
 *	Include Header
 */
#include "Layout.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include Style
 */
#include <ING/UI/Style/Style.h>



/**
 *	Include Canvas
 */
#include <ING/UI/Canvas/Canvas.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		Layout::Layout(const String& name, const LayoutNode& rootNode) :
			name(name),
			rootNode(rootNode)
		{



		}

		Layout::~Layout()
		{



		}



		/**
		 *	Release Methods
		 */
		void Layout::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void Layout::SetupFor(ING::UI::Canvas* canvas) {

			for (auto child : canvas->GetNode()->GetChildList()) {

				child->GetElement()->Release();

			}

		}

	}

}
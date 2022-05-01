
/**
 *	Include Header
 */
#include "Element.h"



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
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



namespace ING { 

	namespace UI {

		/**
		 *	Constructors And Destructor
		 */
		Element::Element():
			node(0)
		{

			node = new Node(this);

		}

		Element::~Element()
		{



		}



		/**
		 *	Release Methods
		 */
		void Element::Release() {

			node->Release();

			delete this;
		}

	}

}
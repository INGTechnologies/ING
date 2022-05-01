
/**
 *	Include Header
 */
#include "DrawableElement.h"



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
		DrawableElement::DrawableElement():
			IElement()
		{



		}

		DrawableElement::~DrawableElement()
		{



		}



		/**
		 *	Release Methods
		 */
		void DrawableElement::Release() {

			IElement::Release();

		}

	}

}
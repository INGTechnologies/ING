
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

		ING_BEGIN_REFLECTED_CLASS
			(DrawableElement, C_Element)

			ING_CLASS_CONSTRUCTOR
				(DrawableElement, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()

		/**
		 *	Constructors And Destructor
		 */
		void DrawableElement::Constructor(const String& name)
		{

			C_Element::Constructor(name);

		}



		/**
		 *	Release Methods
		 */
		void DrawableElement::Release() {

			C_Element::Release();

		}

	}

}
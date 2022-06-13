
/**
 *	Include Header
 */
#include "Canvas.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



namespace ING {

	namespace ImmediateGUI {

		ING_BEGIN_REFLECTED_CLASS
			(C_Canvas, UI::C_Canvas)

			ING_CLASS_CONSTRUCTOR
				(C_Canvas, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Canvas::Constructor(const String& name) {

			UI::C_Canvas::Constructor(name);

		}



		/**
		 *	Release Methods
		 */
		void C_Canvas::Release() {

			UI::C_Canvas::Release();

		}

	}

}
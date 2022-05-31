
/**
 *	Include Header
 */
#include "Canvas.h"



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



namespace ING { 

	namespace UI {

		ING_BEGIN_REFLECTED_CLASS
			(C_Canvas, C_Element)

			ING_CLASS_CONSTRUCTOR
				(C_Canvas, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()

		/**
		 *	Constructors And Destructor
		 */
		void C_Canvas::Constructor(const String& name)
		{

			C_Element::Constructor(name);

		}



		/**
		 *	Release Methods
		 */
		void C_Canvas::Release() {

			C_Element::Release();
		}



		/**
		 *	Methods
		 */
		void	C_Canvas::Start() {

			C_Element::Start();

		}

		void	C_Canvas::PreUpdate() {

			C_Element::PreUpdate();

		}

		void	C_Canvas::Update() {

			C_Element::Update();

		}

		void	C_Canvas::LateUpdate() {

			C_Element::LateUpdate();

		}

		void	C_Canvas::PreRender() {

			C_Element::PreRender();

		}

		void	C_Canvas::Render() {

			C_Element::Render();

		}

		void	C_Canvas::LateRender() {

			C_Element::LateRender();

		}

		void	C_Canvas::Resize() {

			C_Element::Resize();

		}

	}

}
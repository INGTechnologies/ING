
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
			(Canvas, IElement)

			ING_CLASS_CONSTRUCTOR
				(Canvas, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()

		/**
		 *	Constructors And Destructor
		 */
		void Canvas::Constructor(const String& name)
		{

			IElement::Constructor(name);

		}



		/**
		 *	Release Methods
		 */
		void Canvas::Release() {

			IElement::Release();
		}



		/**
		 *	Methods
		 */
		void	Canvas::Start() {

			IElement::Start();

		}

		void	Canvas::PreUpdate() {

			IElement::PreUpdate();

		}

		void	Canvas::Update() {

			IElement::Update();

		}

		void	Canvas::LateUpdate() {

			IElement::LateUpdate();

		}

		void	Canvas::PreRender() {

			IElement::PreRender();

		}

		void	Canvas::Render() {

			IElement::Render();

		}

		void	Canvas::LateRender() {

			IElement::LateRender();

		}

		void	Canvas::Resize() {

			IElement::Resize();

		}

	}

}
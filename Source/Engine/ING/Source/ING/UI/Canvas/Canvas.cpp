
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

		/**
		 *	Constructors And Destructor
		 */
		Canvas::Canvas(const String& name):
			IElement(name)
		{



		}

		Canvas::~Canvas()
		{



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
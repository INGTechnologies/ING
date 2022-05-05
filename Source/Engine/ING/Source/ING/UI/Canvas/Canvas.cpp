
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
		ICanvas::ICanvas():
			IElement()
		{



		}

		ICanvas::~ICanvas()
		{



		}



		/**
		 *	Release Methods
		 */
		void ICanvas::Release() {

			IElement::Release();
		}



		/**
		 *	Methods
		 */
		void	ICanvas::Start() {

			IElement::Start();

		}

		void	ICanvas::PreUpdate() {

			IElement::PreUpdate();

		}

		void	ICanvas::Update() {

			IElement::Update();

		}

		void	ICanvas::LateUpdate() {

			IElement::LateUpdate();

		}

		void	ICanvas::PreRender() {

			IElement::PreRender();

		}

		void	ICanvas::Render() {

			IElement::Render();

		}

		void	ICanvas::LateRender() {

			IElement::LateRender();

		}

	}

}
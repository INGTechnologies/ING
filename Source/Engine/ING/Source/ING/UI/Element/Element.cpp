
/**
 *	Include Header
 */
#include "Element.h"



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
		IElement::IElement():
			node(0),

			size(Math::RVector2()),
			padding(Math::RVector4()),
			margin(Math::RVector4())
		{

			node = new Node(this);
			style = new Style();

		}

		IElement::~IElement()
		{



		}



		/**
		 *	Release Methods
		 */
		void IElement::Release() {

			node->Release();

			if(style != 0)
				style->Release();

			delete this;
		}



		/**
		 *	Properties
		 */
		void IElement::SetStyle(Style* style) {

			this->style = style;

		}

		void IElement::ReleaseStyle() {

			this->style->Release();

			this->style = 0;

		}



		/**
		 *	Methods
		 */
		void	IElement::Start() {



		}

		void	IElement::PreUpdate() {



		}

		void	IElement::Update() {



		}

		void	IElement::LateUpdate() {

			if (style != 0) {

				style->Apply(this);

			}

		}

		void	IElement::PreRender() {



		}

		void	IElement::Render() {



		}

		void	IElement::LateRender() {



		}

	}

}
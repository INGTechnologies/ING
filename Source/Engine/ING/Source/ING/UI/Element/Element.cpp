
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

			node->Start();

		}

		void	IElement::PreUpdate() {

			node->PreUpdate();

		}

		void	IElement::Update() {

			node->Update();

		}

		void	IElement::LateUpdate() {

			if (style != 0) {

				style->Apply(this);

			}

			node->LateUpdate();

		}

		void	IElement::PreRender() {

			node->PreRender();

		}

		void	IElement::Render() {

			node->Render();

		}

		void	IElement::LateRender() {

			node->LateRender();

		}

	}

}
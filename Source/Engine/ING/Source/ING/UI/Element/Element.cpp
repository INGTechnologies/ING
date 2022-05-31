
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

		ING_BEGIN_REFLECTED_CLASS
		(C_Element, Reflection::C_Object)

			ING_CLASS_CONSTRUCTOR
				(C_Element, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Element::Constructor(const String& name)
		{

			node = new Node(this);

			size = (Math::RVector2());
			padding = (Math::RVector4());
			margin = (Math::RVector4());

			style = new Style();

			this->name = name;

		}



		/**
		 *	Release Methods
		 */
		void C_Element::Release() {

			node->Release();

			if(style != 0)
				style->Release();

			delete this;
		}



		/**
		 *	Properties
		 */
		void C_Element::SetStyle(Style* style) {

			this->style = style;

		}

		void C_Element::ReleaseStyle() {

			this->style->Release();

			this->style = 0;

		}



		/**
		 *	Methods
		 */
		void	C_Element::Start() {

			node->Start();

		}

		void	C_Element::PreUpdate() {

			node->PreUpdate();

		}

		void	C_Element::Update() {

			node->Update();

		}

		void	C_Element::LateUpdate() {

			if (style != 0) {

				style->Apply(this);

			}

			node->LateUpdate();

		}

		void	C_Element::PreRender() {

			node->PreRender();

		}

		void	C_Element::Render() {

			node->Render();

		}

		void	C_Element::LateRender() {

			node->LateRender();

		}

		void	C_Element::Resize() {

			node->Resize();

		}

	}

}
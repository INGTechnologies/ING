
/**
 *	Include Header
 */
#include "Style.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include Element
 */
#include <ING/UI/Element/Element.h>



namespace ING { 

	namespace UI {

		/**
		 *	Constructors And Destructor
		 */
		Style::Style()
		{

			SetPosition	(UI_DVECTOR2(0,0));
			SetSize		(UI_DVECTOR2(0,0));
			SetPadding	(UI_DVECTOR4(0,0,0,0));
			SetMargin	(UI_DVECTOR4(0,0,0,0));

		}

		Style::~Style()
		{



		}



		/**
		 *	Release Methods
		 */
		void Style::Release() { 

			delete this;
		}



		/**
		 *	Methods
		 */
		void Style::SetPosition	(const DVector2& position) {

			this->position = position;

		}

		void Style::SetSize		(const DVector2& size) {

			this->size = size;

		}

		void Style::SetCenter	(const DVector2& center) {

			this->center = center;

		}

		void Style::SetPadding	(const DVector4& padding) {

			this->padding = padding;

		}

		void Style::SetMargin	(const DVector4& margin) {

			this->margin = margin;

		}

		void Style::CopyFrom	(Style* srcStyle) {

			*this = *srcStyle;

		}
		
		void Style::CopyTo		(Style* dstStyle) {

			*dstStyle = *this;

		}

		void Style::Apply(IElement* element) {

			element->position = position(this, element);
			element->size = size(this, element);
			element->center = center(this, element);
			element->padding = padding(this, element);
			element->margin = margin(this, element);

		}

	}

}
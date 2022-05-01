
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

			SetPosition(UI_DVECTOR2(0,0));
			SetSize(UI_DVECTOR2(0,0));
			SetPadding(UI_DVECTOR4(0,0,0,0));
			SetMargin(UI_DVECTOR4(0,0,0,0));

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
		void Style::SetPosition	(DVector2Function positionFunction) {

			this->positionFunction = positionFunction;

		}

		void Style::SetSize		(DVector2Function sizeFunction) {

			this->sizeFunction = sizeFunction;

		}

		void Style::SetPadding	(DVector4Function paddingFunction) {

			this->paddingFunction = paddingFunction;

		}

		void Style::SetMargin	(DVector4Function marginFunction) {

			this->marginFunction = marginFunction;

		}

		void Style::CopyFrom	(Style* srcStyle) {

			*this = *srcStyle;

		}
		
		void Style::CopyTo		(Style* dstStyle) {

			*dstStyle = *this;

		}

		void Style::Apply(IElement* element) {

			element->position = positionFunction(this, element);
			element->size = sizeFunction(this, element);
			element->padding = paddingFunction(this, element);
			element->margin = marginFunction(this, element);

		}

	}

}
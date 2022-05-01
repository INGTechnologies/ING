#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



namespace ING {

	namespace UI {

		class Node;

		class Style;
		class IElement;



		typedef float				(*DFloatFunction)	(ING::UI::Style* style, ING::UI::IElement* element);
		typedef ING::Math::RVector2	(*DVector2Function)	(ING::UI::Style* style, ING::UI::IElement* element);
		typedef ING::Math::RVector3	(*DVector3Function)	(ING::UI::Style* style, ING::UI::IElement* element);
		typedef ING::Math::RVector4	(*DVector4Function)	(ING::UI::Style* style, ING::UI::IElement* element);

#define	UI_PARENT_WIDTH\
		(element->GetNode()->GetParent()->GetElement()->GetSize().x)

#define	UI_PARENT_HEIGHT\
		(element->GetNode()->GetParent()->GetElement()->GetSize().y)

#define	UI_PARENT_POSITION_X\
		(element->GetNode()->GetParent()->GetElement()->GetPosition().x)

#define	UI_PARENT_POSITION_Y\
		(element->GetNode()->GetParent()->GetElement()->GetPosition().y)

#define UI_DFLOAT(x) (\
		[](ING::UI::Style* style, ING::UI::IElement* element) -> float {\
			return (x);\
		}\
		)

#define UI_DVECTOR2(x, y) (\
		[](ING::UI::Style* style, ING::UI::IElement* element) -> ING::Math::RVector2 {\
			return ING::Math::RVector2(x, y);\
		}\
		)

#define UI_DVECTOR3(x, y, z) (\
		[](ING::UI::Style* style, ING::UI::IElement* element) -> ING::Math::RVector3 {\
			return ING::Math::RVector3(x, y, z);\
		}\
		)

#define UI_DVECTOR4(x, y, z, w) (\
		[](ING::UI::Style* style, ING::UI::IElement* element) -> ING::Math::RVector4 {\
			return ING::Math::RVector4(x, y, z, w);\
		}\
		)



		class ING_API Style
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Style	();
			~Style	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			DVector2Function		positionFunction;
			DVector2Function		sizeFunction;
			DVector4Function		paddingFunction;
			DVector4Function		marginFunction;



			/**
			 *	Methods
			 */
		public:
			void					SetPosition	(DVector2Function positionFunction);
			void					SetSize		(DVector2Function sizeFunction);
			void					SetPadding	(DVector4Function paddingFunction);
			void					SetMargin	(DVector4Function marginFunction);

			virtual void			CopyFrom	(Style* srcStyle);
			virtual void			CopyTo		(Style* dstStyle);

			virtual void			Apply		(IElement* element);

		};

	}

}
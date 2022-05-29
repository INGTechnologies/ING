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



/**
 *	Include Reflection
 */
#include <ING/Reflection/Type/Type.h>
#include <ING/Reflection/Namespace/Namespace.h>
#include <ING/Reflection/Object/Object.h>
#include <ING/Reflection/Object/Function/Function.h>
#include <ING/Reflection/Context/Context.h>
#include <ING/Reflection/Class/Class.h>

using namespace ING::Reflection;



namespace ING {

	namespace UI {

		class Node;

		class Style;
		class IElement;

		struct DFloat;

		struct DVector2;
		struct DVector3;
		struct DVector4;



		/**
		 *	Dynamic Value Type Functions
		 */
		typedef float				(*DFloatFunction)	(ING::UI::Style* style, ING::UI::IElement* element, const DFloat& instance);
		typedef ING::Math::RVector2	(*DVector2Function)	(ING::UI::Style* style, ING::UI::IElement* element, const DVector2& instance);
		typedef ING::Math::RVector3	(*DVector3Function)	(ING::UI::Style* style, ING::UI::IElement* element, const DVector3& instance);
		typedef ING::Math::RVector4	(*DVector4Function)	(ING::UI::Style* style, ING::UI::IElement* element, const DVector4& instance);



		/**
		 *	Dynamic Value Type Structs
		 */
		struct DFloat {

			DFloat(DFloatFunction function, const std::vector<float>& capturedFloatVector) :
				function(function),
				capturedFloatVector(capturedFloatVector)
			{



			}

			DFloat() :
				function([](ING::UI::Style* style, ING::UI::IElement* element, const DFloat& instance) -> float {return 0; })
			{



			}

			DFloatFunction function;

			std::vector<float> capturedFloatVector;

			float operator()(ING::UI::Style* style, ING::UI::IElement* element) {

				return function(style, element, *this);

			}

		};

		struct DVector2 {

			DVector2(DVector2Function function, const std::vector<float>& capturedFloatVector) :
				function(function),
				capturedFloatVector(capturedFloatVector)
			{



			}

			DVector2() :
				function([](ING::UI::Style* style, ING::UI::IElement* element, const DVector2& instance) -> ING::Math::RVector2 {return ING::Math::RVector2(); })
			{



			}

			DVector2Function function;
			
			std::vector<float> capturedFloatVector;

			ING::Math::RVector2 operator()(ING::UI::Style* style, ING::UI::IElement* element) {

				return function(style, element, *this);

			}

		};

		struct DVector3 {

			DVector3(DVector3Function function, const std::vector<float>& capturedFloatVector) :
				function(function),
				capturedFloatVector(capturedFloatVector)
			{



			}

			DVector3() :
				function([](ING::UI::Style* style, ING::UI::IElement* element, const DVector3& instance) -> ING::Math::RVector3 { return ING::Math::RVector3(); })
			{



			}

			DVector3Function function;

			std::vector<float> capturedFloatVector;

			ING::Math::RVector3 operator()(ING::UI::Style* style, ING::UI::IElement* element) {

				return function(style, element, *this);

			}

		};

		struct DVector4 {

			DVector4(DVector4Function function, const std::vector<float>& capturedFloatVector) :
				function(function),
				capturedFloatVector(capturedFloatVector)
			{



			}

			DVector4() :
				function([](ING::UI::Style* style, ING::UI::IElement* element, const DVector4& instance) -> ING::Math::RVector4 { return ING::Math::RVector4(); })
			{



			}

			DVector4Function function;

			std::vector<float> capturedFloatVector;

			ING::Math::RVector4 operator()(ING::UI::Style* style, ING::UI::IElement* element) {

				return function(style, element, *this);

			}

		};



		/**
		 *	MainClass
		 */
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
			DVector2				position;
			DVector2				size;
			DVector2				center;
			DVector4				padding;
			DVector4				margin;



			/**
			 *	Methods
			 */
		public:
			void					SetPosition	(const DVector2& position);
			void					SetSize		(const DVector2& size);
			void					SetCenter	(const DVector2& center);
			void					SetPadding	(const DVector4& padding);
			void					SetMargin	(const DVector4& margin);

			virtual void			CopyFrom	(Style* srcStyle);
			virtual void			CopyTo		(Style* dstStyle);

			virtual void			Apply		(IElement* element);

		};

	}

}



/**
 *	Define Macros
 */
#define	UI_PARENT_SIZE_X\
		(element->GetNode()->GetParent()->GetElement()->GetSize().x)

#define	UI_PARENT_SIZE_Y\
		(element->GetNode()->GetParent()->GetElement()->GetSize().y)

#define	UI_PARENT_SIZE\
		(element->GetNode()->GetParent()->GetElement()->GetSize())



#define	UI_PARENT_POSITION_X\
		(element->GetNode()->GetParent()->GetElement()->GetPosition().x)

#define	UI_PARENT_POSITION_Y\
		(element->GetNode()->GetParent()->GetElement()->GetPosition().y)

#define	UI_PARENT_POSITION\
		(element->GetNode()->GetParent()->GetElement()->GetPosition())



#define	UI_PARENT_PADDING_X\
		(element->GetNode()->GetParent()->GetElement()->GetPadding().x)

#define	UI_PARENT_PADDING_Y\
		(element->GetNode()->GetParent()->GetElement()->GetPadding().y)

#define	UI_PARENT_PADDING_Z\
		(element->GetNode()->GetParent()->GetElement()->GetPadding().z)

#define	UI_PARENT_PADDING_W\
		(element->GetNode()->GetParent()->GetElement()->GetPadding().w)

#define	UI_PARENT_PADDING\
		(element->GetNode()->GetParent()->GetElement()->GetPadding().x)



#define	UI_PARENT_MARGIN_X\
		(element->GetNode()->GetParent()->GetElement()->GetMargin().x)

#define	UI_PARENT_MARGIN_Y\
		(element->GetNode()->GetParent()->GetElement()->GetMargin().y)

#define	UI_PARENT_MARGIN_Z\
		(element->GetNode()->GetParent()->GetElement()->GetMargin().z)

#define	UI_PARENT_MARGIN_W\
		(element->GetNode()->GetParent()->GetElement()->GetMargin().w)

#define	UI_PARENT_MARGIN\
		(element->GetNode()->GetParent()->GetElement()->GetMargin().x)



#define	UI_GET(index)\
		(instance.capturedFloatVector[index])



#define UI_DFLOAT(x,...) (\
			ING::UI::DFloat(\
				[](ING::UI::Style* style, ING::UI::IElement* element, const DFloat& instance) -> ING::Math::RVector2 {\
					return (x);\
				},\
				{ ##__VA_ARGS__ }\
			)\
		)

#define UI_DVECTOR2(x, y,...) (\
			ING::UI::DVector2(\
				[](ING::UI::Style* style, ING::UI::IElement* element, const ING::UI::DVector2& instance) -> ING::Math::RVector2 {\
					return ING::Math::RVector2(x, y);\
				},\
				{ ##__VA_ARGS__ }\
			)\
		)

#define UI_DVECTOR3(x, y, z,...) (\
			ING::UI::DVector3(\
				[](ING::UI::Style* style, ING::UI::IElement* element, const ING::UI::DVector3& instance) -> ING::Math::RVector3 {\
					return ING::Math::RVector3(x, y, z);\
				},\
				{ ##__VA_ARGS__ }\
			)\
		)

#define UI_DVECTOR4(x, y, z, w,...) (\
			ING::UI::DVector4(\
				[](ING::UI::Style* style, ING::UI::IElement* element, const ING::UI::DVector4& instance) -> ING::Math::RVector4 {\
					return ING::Math::RVector4(x, y, z, w);\
				},\
				{ ##__VA_ARGS__ }\
			)\
		)
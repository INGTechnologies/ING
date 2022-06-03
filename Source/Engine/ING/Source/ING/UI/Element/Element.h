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
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	namespace UI {

		class Node;
		class Style;



		class ING_API C_Element : public Reflection::C_Object
		{

		public:
			friend class Style;



			ING_REFLECT_CLASS(C_Element, Reflection::C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void		Constructor	(const String& name);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			Node*					node;
			Style*					style;

			Math::RVector2			position;//(x, y)
			Math::RVector2			size;	//(width, height)
			Math::RVector2			center;	//(width, height)
			Math::RVector4			padding; //(top, right, bottom, left)
			Math::RVector4			margin;	//(top, right, bottom, left)

		protected:
			String					name;

		public:
			Node*					GetNode		() { return node; }
			Style*					GetStyle	() { return style; }
			void					SetStyle	(Style* style);
			void					ReleaseStyle();

			const Math::RVector2&	GetPosition	() { return position; }
			const Math::RVector2&	GetSize		() { return size; }
			const Math::RVector2&	GetCenter	() { return center; }
			const Math::RVector4&	GetPadding	() { return padding; }
			const Math::RVector4&	GetMargin	() { return margin; }

			const String&			GetName		() { return name; }



			/**
			 *	Methods
			 */
		public:
			virtual void			Start		();

			virtual void			PreUpdate	();
			virtual void			Update		();
			virtual void			LateUpdate	();

			virtual void			PreRender	();
			virtual void			Render		();
			virtual void			LateRender	();

			virtual void			Resize		();

		};

	}

}
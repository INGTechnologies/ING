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



namespace ING {

	namespace Rendering {

		class C_Drawable;

		class LayerSystem;



		class ING_API IDrawableFilter
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDrawableFilter	(const String& name);
			~IDrawableFilter	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String name;

			SmartArray<C_Drawable*> drawableArray;

			IdGenerator		idGenerator;

		public:
			String				GetName			() { return name; }

			const SmartArray<C_Drawable*>& GetDrawableArray	() { return drawableArray; }



			/**
			 *	Methods
			 */
		public:
			void	AddDrawable		(C_Drawable* drawable);
			void	RemoveDrawable	(C_Drawable* drawable);

		};

	}

}
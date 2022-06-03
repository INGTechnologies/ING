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
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class Camera;



	namespace Rendering {

		class IDevice;

		class IDeviceContext;

		class Scene;

		class C_Drawable;



		class ING_API C_Renderer : public Reflection::C_Object
		{

			ING_REFLECT_CLASS(C_Renderer, Reflection::C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			virtual void RenderDrawables(Camera* camera, const String& filterName, const String& passName);
			virtual void RenderDrawable	(Camera* camera, C_Drawable* drawable, const String& passName);

		};

	}

}
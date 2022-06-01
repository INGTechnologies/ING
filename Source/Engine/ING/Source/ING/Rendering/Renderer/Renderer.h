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
#include <ING/Reflection/Type/Type.h>
#include <ING/Reflection/Namespace/Namespace.h>
#include <ING/Reflection/Object/Object.h>
#include <ING/Reflection/Object/Function/Function.h>
#include <ING/Reflection/Context/Context.h>
#include <ING/Reflection/Class/Class.h>

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
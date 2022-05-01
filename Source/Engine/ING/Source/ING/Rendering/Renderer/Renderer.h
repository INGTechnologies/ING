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

	class Camera;



	namespace Rendering {

		class IDevice;

		class IDeviceContext;

		class Scene;

		class IDrawable;



		class ING_API IRenderer
		{
			/**
			 *	Constructors And Destructor
			 */
		public:
			IRenderer	();
			~IRenderer	();



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
			virtual void RenderDrawable	(Camera* camera, IDrawable* drawable, const String& passName);

		};

	}

}
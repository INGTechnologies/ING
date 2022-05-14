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
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;

		class LayerSystem;



		class ING_API UIDrawable : public IDrawable
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			UIDrawable(LayerSystem* system);
			~UIDrawable();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(Camera* camera, const String& passName) override;

		};

	}

}
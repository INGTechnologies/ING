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

	class C_Camera;



	namespace Rendering {

		class C_Renderer;

		class IDevice;

		class IDeviceContext;

		class C_Pass;

		class LayerSystem;



		class ING_API C_UIDrawable : public C_Drawable
		{

			ING_REFLECT_CLASS(C_UIDrawable, Reflection::C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor(LayerSystem* system);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(C_Camera* camera, const String& passName) override;

		};

	}

}
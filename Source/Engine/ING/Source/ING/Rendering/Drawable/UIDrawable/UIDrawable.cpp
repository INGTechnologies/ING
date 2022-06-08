
/**
 * Include Header
 */
#include "UIDrawable.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>




namespace ING {

	namespace Rendering {

		ING_BEGIN_REFLECTED_CLASS
			(C_UIDrawable, C_Drawable)

			ING_CLASS_CONSTRUCTOR
				(C_UIDrawable, LayerSystem*)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_UIDrawable::Constructor(LayerSystem* system) {

			C_Drawable::Constructor(system);

		}



		/**
		 *	Release Methods
		 */
		void C_UIDrawable::Release() {

			C_Drawable::Release();

		}



		/**
		 *	Methods
		 */
		void C_UIDrawable::Draw(C_Camera* camera, const String& passName) {



		}

	}

}
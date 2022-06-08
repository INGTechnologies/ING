
/**
 * Include Header
 */
#include "CameraData.h"



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
 *	Include Rendering Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>




namespace ING {

	namespace Rendering {

		ING_BEGIN_REFLECTED_CLASS
			(C_CameraData, C_Object)

			/**
			 *	Constructor
			 */
			ING_CLASS_CONSTRUCTOR
				(C_CameraData, C_Camera*)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_CameraData::Constructor(C_Camera* camera)
		{

			this->camera = camera;

		}



		/**
		 *	Release Method
		 */
		void C_CameraData::Release() {

			C_Object::Release();

		}

	}

}
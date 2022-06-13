
/**
 * Include Header
 */
#include "Renderer.h"



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



/**
 *	Include Rendering CameraData
 */
#include <ING/Rendering/CameraData/CameraData.h>



/**
 *	Include Rendering SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>




namespace ING {

	namespace StandardRP {

		ING_BEGIN_REFLECTED_CLASS
			(C_Renderer, Rendering::C_Renderer)

			ING_CLASS_CONSTRUCTOR
				(C_Renderer)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Renderer::Constructor() {

			Rendering::C_Renderer::Constructor();

		}



		/**
		 *	Release Methods
		 */
		void C_Renderer::Release() {

			Rendering::C_Renderer::Release();

		}

	}

}
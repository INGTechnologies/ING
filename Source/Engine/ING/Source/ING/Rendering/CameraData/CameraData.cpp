
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

		/**
		 *	Constructors And Destructor
		 */
		ICameraData::ICameraData(Camera* camera) :
			camera(camera)
		{



		}

		ICameraData::~ICameraData() {

				

		}



		/**
		 *	Release Method
		 */
		void ICameraData::Release() {


			delete this;
		}

	}

}
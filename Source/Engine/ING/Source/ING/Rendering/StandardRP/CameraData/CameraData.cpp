
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

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			CameraData::CameraData(Camera* camera) : ICameraData(camera) {

				if (camera->GetTargetMode() == CAMERA_TARGET_SCREEN && camera->GetScreen() != 0) {

					mainRTV = camera->GetScreen()->GetSwapChain()->GetRenderTargetView();

				}

			}

			CameraData::~CameraData() {

				

			}



			/**
			 *	Release Method
			 */
			void CameraData::Release() {



				ICameraData::Release();
			}

		}

	}

}
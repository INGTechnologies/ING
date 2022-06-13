
/**
 * Include Header
 */
#include "Pipeline.h"



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
			(C_Pipeline, Rendering::C_Pipeline)

			ING_CLASS_CONSTRUCTOR
				(C_Pipeline, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Pipeline::Constructor(const String& name) {

			Rendering::C_Pipeline::Constructor(name);

		}



		/**
		 *	Release Methods
		 */
		void C_Pipeline::Release() {

			Rendering::C_Pipeline::Release();

		}



		/**
		 *	Methods
		 */
		void C_Pipeline::SetupCamera	(Rendering::IDeviceContext* context, C_Camera* camera) {

			Rendering::C_Pipeline::SetupCamera(context, camera);

		}

		void C_Pipeline::ClearCameraData(C_Camera* camera) {

			Rendering::C_Pipeline::ClearCameraData(camera);

		}

		bool C_Pipeline::Render	(Rendering::IDeviceContext* context) {

			BeginRender(context);

			for (C_Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() == this) {

					Rendering::C_CameraData* renderingData = (Rendering::C_CameraData*)camera->GetRenderingData();



					for (auto pass : passVector) {

						if (!pass->Render(context, camera)) return false;

					}

				}

			}

			EndRender(context);

			return true;
		}

	}

}
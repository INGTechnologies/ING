
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
 *	Include StandardRP First Pass
 */
#include <ING/Rendering/StandardRP/Pass/First/First.h>



/**
 *	Include StandardRP Final Pass
 */
#include <ING/Rendering/StandardRP/Pass/Final/Final.h>



/**
 *	Include Rendering Data
 */
#include <ING/Rendering/StandardRP/CameraData/CameraData.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include RenderTargetView
 */
#include <ING/Rendering/API/View/RenderTargetView/RenderTargetView.h>



/**
 *	Include StandardRP Renderer
 */
#include <ING/Rendering/StandardRP/Renderer/Renderer.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Engine
 */
#include <ING/Rendering/Engine/Engine.h>




namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			Pipeline::Pipeline(String name) : IPipeline(name) {

				/**
				 *	Create Default Passes
				 */
				firstPass = new FirstPass	("StandardRP.FirstPass");				 
				finalPass = new FinalPass	("StandardRP.FinalPass");



				/**
				 *	Create Renderer
				 */
				renderer = new StandardRP::Renderer();

			}

			Pipeline::~Pipeline() {



			}



			/**
			 *	Release Methods
			 */
			void Pipeline::Release() {

				IPipeline::Release();

			}



			/**
			 *	Methods
			 */
			void Pipeline::SetupCamera(IDeviceContext* context, Camera* camera) {

				CameraData* renderingData = new CameraData(camera);

				camera->SetRenderingData(renderingData);

				IPipeline::SetupCamera(context, camera);

			}

			void Pipeline::ClearCameraData(Camera* camera) {

				CameraData* renderingData = (CameraData*)camera->GetRenderingData();

				renderingData->Release();

				IPipeline::ClearCameraData(camera);

			}

			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::BeginRender(context);

				for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

					CameraData* renderingData = (CameraData*)camera->GetRenderingData();

					context->OMSetRenderTargets(renderingData->GetMainRTV(),0);



					for (auto pass : passVector) {

						RENDERING_ASSERTION(firstPass->Render(context, camera));

					}



					if (camera->GetTargetMode() == CAMERA_TARGET_SCREEN) {

						camera->GetScreen()->GetSwapChain()->Present();

					}

				}
				
				IPipeline::EndRender(context);

				return true;

			}

		}

	}

}
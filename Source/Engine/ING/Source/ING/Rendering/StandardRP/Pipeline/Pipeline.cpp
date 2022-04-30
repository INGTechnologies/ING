
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
				targetFirstPass	= new FirstPass	("Standard Main Pass");
				firstPass		= targetFirstPass;
				 
				targetFinalPass = new FinalPass	("Standard Final Pass");
				finalPass		= targetFinalPass;



				/**
				 *	Create Renderer
				 */
				targetRenderer = new StandardRP::Renderer();

				renderer = targetRenderer;

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
			 *	Properties
			 */
			void Pipeline::SetFirstPass	(IPass* firstPass) {

				/* New First Pass Will Be Used In Next Frame */
				targetFirstPass = firstPass;

			}

			void Pipeline::SetFinalPass	(IPass* finalPass) {

				/* New Main Pass Will Be Used In Next Frame */
				targetFinalPass = finalPass;

			}




			/**
			 *	Methods
			 */
			void Pipeline::SetupCamera(IDeviceContext* context, Camera* camera) {

				CameraData* renderingData = new CameraData(camera);

				camera->SetRenderingData(renderingData);

			}

			void Pipeline::ClearCameraData(Camera* camera) {

				CameraData* renderingData = (CameraData*)camera->GetRenderingData();

				renderingData->Release();

			}

			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::BeginRender(context);

				for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

					CameraData* renderingData = (CameraData*)camera->GetRenderingData();

					context->OMSetRenderTargets(renderingData->GetMainRTV(),0);


					/* Render First Pass */
					firstPass = targetFirstPass;

					RENDERING_ASSERTION(firstPass->Render(context, camera));



					/* Render Final Pass */
					finalPass = targetFinalPass;

					RENDERING_ASSERTION(finalPass->Render(context, camera));


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
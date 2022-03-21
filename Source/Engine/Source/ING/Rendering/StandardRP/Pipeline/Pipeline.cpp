
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
 *	Include Rendering System
 */
#include <ING/Rendering/System/System.h>



/**
 *	Include Rendering Data
 */
#include <ING/Rendering/StandardRP/Data/Data.h>



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




namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			Pipeline::Pipeline(std::string name) : IPipeline(name) {

				/**
				 *	Create Default Passes
				 */
				targetFirstPass	= new FirstPass	("Standard Main Pass");
				firstPass		= targetFirstPass;
				 
				targetFinalPass = new FinalPass	("Standard Final Pass");
				finalPass		= targetFinalPass;



				/**
				 *	Create SubRPs
				 */
				AddSubPipeline(new SubRP::Pipeline("After First Pipeline"), 0);

				AddSubPipeline(new SubRP::Pipeline("Befrore Final Pipeline"), 0);



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

				Data* renderingData = new Data(camera);

				camera->SetRenderingData(renderingData);

			}

			void Pipeline::ClearRenderingData(Camera* camera) {

				Data* renderingData = (Data*)camera->GetRenderingData();

			}

			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::BeginRender(context);

				for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

					Data* renderingData = (Data*)camera->GetRenderingData();

					context->OMSetRenderTargets(renderingData->GetMainRTV(),0);


					/* Render First Pass */
					firstPass = targetFirstPass;

					FirstPassInput	firstPassInput;
					FirstPassOutput	firstPassOutput;

					RENDERING_ASSERTION(firstPass->Render(context, camera, &firstPassInput, &firstPassOutput));



					/* Render Sub Pipelines */
					SubRP::PassInput	subPipelinesInput;

					SubRP::PassOutput	subPipelinesOutput;

					RENDERING_ASSERTION(RenderSubPipelines(context, camera, subPipelinesInput, subPipelinesOutput));



					/* Render Final Pass */
					finalPass = targetFinalPass;

					FinalPassInput	finalPassInput;
					FinalPassOutput	finalPassOutput;

					RENDERING_ASSERTION(finalPass->Render(context, camera, &finalPassInput, &finalPassOutput));


					if (camera->GetTargetMode() == CAMERA_TARGET_SCREEN) {

						camera->GetScreen()->GetSwapChain()->Present();

					}

				}
				
				IPipeline::EndRender(context);

				return true;

			}

			bool Pipeline::RenderSubPipelines(IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output) {

				unsigned int subPipelineVectorSize = subPipelineVector.size();

				SubRP::PassInput renderRS = input;

				for (unsigned int i = 0; i < subPipelineVectorSize; ++i) {

					SubRP::Pipeline* pipeline = subPipelineVector[i];

					SubRP::PassOutput passOutput;

					RENDERING_ASSERTION(pipeline->SubRender(context, camera, renderRS, passOutput));

					renderRS += passOutput;

				}

				output += renderRS;

				return true;
			}

			void Pipeline::AddSubPipeline	(SubRP::Pipeline* subPipeline) {

				unsigned int index = subPipelineVector.size();

				subPipelineVector.resize(index + 1);

				subPipelineVector[index] = subPipeline;

				subPipelineName2supPipeLineIndex[subPipeline->GetName()] = index;

			}

			void Pipeline::AddSubPipeline	(SubRP::Pipeline* subPipeline, unsigned int index) {

				unsigned int subPipelineVectorSize = subPipelineVector.size();

				subPipelineVector.resize(subPipelineVectorSize + 1);

				for (unsigned int i = index + 1; i < subPipelineVector.size(); ++i) {

					subPipelineVector[i] = subPipelineVector[i - 1];

					subPipelineName2supPipeLineIndex[subPipelineVector[i]->GetName()] = i;

				}

				subPipelineVector[index] = subPipeline;

				subPipelineName2supPipeLineIndex[subPipeline->GetName()] = index;

			}

		}

	}

}

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
				afterFirstPassSubPipeline	= new SubRP::Pipeline("After First Pass Sub Pipeline");

				beforeFinalPassSubPipeline	= new SubRP::Pipeline("Befrore Final Pass Sub Pipeline");

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
			void Pipeline::Render(IDeviceContext* context) {

				IPipeline::Render(context);

				for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

					/* Draw First Pass */
					firstPass = targetFirstPass;

					FirstPassInput	firstPassInput;
					FirstPassOutput	firstPassOutput;

					firstPass->Render(context, camera, &firstPassInput, &firstPassOutput);



					SubRP::PassInput	afterFirstPassSubPipelineInput;
					SubRP::PassOutput	afterFirstPassSubPipelineOutput;

					afterFirstPassSubPipeline->SubRender(context, camera, &afterFirstPassSubPipelineInput, &afterFirstPassSubPipelineOutput);



					SubRP::PassInput	beforeFinalPassSubPipelineInput = afterFirstPassSubPipelineOutput;
					SubRP::PassOutput	beforeFinalPassSubPipelineOutput;

					beforeFinalPassSubPipeline->SubRender(context, camera, &beforeFinalPassSubPipelineInput, &beforeFinalPassSubPipelineOutput);



					/* Get Final Pass */
					finalPass = targetFinalPass;

					FinalPassInput	finalPassInput;
					FinalPassOutput	finalPassOutput;

					finalPass->Render(context, camera, &finalPassInput, &finalPassOutput);

				}

			}

		}

	}

}
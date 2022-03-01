
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
 *	Include StandardRP Main Pass
 */
#include <ING/Rendering/StandardRP/Pass/Main/Main.h>



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
				targetMainPass	= new MainPass("Standard Main Pass");
				mainPass		= targetMainPass;

				targetFinalPass = new MainPass("Standard Final Pass");
				finalPass		= targetFinalPass;

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
			void Pipeline::SetMainPass	(IPass* mainPass) {

				/* New Main Pass Will Be Used In Next Frame */
				targetMainPass = mainPass;

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

					/**
					 *	Draw Main Pass
					 */
					/* Get Main Pass */
					mainPass = targetMainPass;

					MainPassInput	mainPassInput;
					MainPassOutput	mainPassOutput;

					mainPass->Render(context, camera, &mainPassInput, &mainPassOutput);



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
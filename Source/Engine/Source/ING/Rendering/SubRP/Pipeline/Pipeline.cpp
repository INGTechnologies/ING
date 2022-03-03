
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
 *	Include SubRP Pass
 */
#include <ING/Rendering/SubRP/Pass/Pass.h>



/**
 *	Include SubRP First Pass
 */
#include <ING/Rendering/SubRP/Pass/First/First.h>



/**
 *	Include SubRP Final Pass
 */
#include <ING/Rendering/SubRP/Pass/Final/Final.h>




namespace ING {

	namespace Rendering {

		namespace SubRP {

			/**
			 *	Constructors And Destructor
			 */
			Pipeline::Pipeline(std::string name) : IPipeline(name) {



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
			void Pipeline::Render(IDeviceContext* context) {

				IPipeline::Render(context);

				/*
				firstPass = targetFirstPass;

				PassInput	firstPassInput;
				PassOutput	firstPassOutput;

				firstPass->Render(context, camera, &firstPassInput, &firstPassOutput);



				finalPass = targetFinalPass;

				PassInput  finalPassInput;
				PassInput  finalPassOutput;

				finalPass->Render(context, camera, &finalPassInput, &finalPassOutput);				
				*/

			}

			void Pipeline::SubRender(IDeviceContext* context, Camera* camera, PassInput* input, PassOutput* output) {

				unsigned int passCount = passVector.size();

				PassInput renderRS = input;

				for (unsigned int i = 0; i < passCount; ++i) {


					IPass* pass = passVector[i];

					PassInput passInput = renderRS;

					PassInput passOutput;

					pass->Render(context, camera, &passInput, &passOutput);

					renderRS = passOutput;

				}

				*output = renderRS;

			}

			unsigned int Pipeline::AddPass(IPass* pass) {

				unsigned int passIndex = passVector.size();

				passVector.push_back(pass);

				return passIndex;

			}

			void		 Pipeline::RemovePass(unsigned int index) {

				passVector.erase(passVector.begin() + index);

			}

		}

	}

}
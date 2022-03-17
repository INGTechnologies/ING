
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



/**
 *	Include Rendering System
 */
#include <ING/Rendering/System/System.h>




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
			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::Render(context);



				return true;
			}

			bool Pipeline::SubRender(IDeviceContext* context, Camera* camera, const PassInput& input, PassOutput& output) {

				unsigned int passCount = passVector.size();

				PassInput renderRS = input;

				for (unsigned int i = 0; i < passCount; ++i) {

					IPass* pass = passVector[i];

					PassOutput passOutput;

					RENDERING_ASSERTION(pass->Render(context, camera, &renderRS, &passOutput));

					renderRS = passOutput;

				}

				output = renderRS;

				return true;
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
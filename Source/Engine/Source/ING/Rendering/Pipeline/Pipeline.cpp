
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




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IPipeline::IPipeline	(std::string name) {

			this->name = name;

		}

		IPipeline::~IPipeline	() {



		}



		/**
		 *	Release Methods
		 */
		void IPipeline::Release() {

			delete this;

		}



		/**
		 *	Properties
		 */
		void IPipeline::SetRenderer(IRenderer* renderer) {

			/* New Renderer Will Be Used In Next Frame */
			targetRenderer = renderer;

		}



		/**
		 *	Methods
		 */
		void IPipeline::Setup	(DeviceContext* context, Camera* camera) {



		}

		void IPipeline::Render	(DeviceContext* context) {

			/* Set Renderer */
			renderer = targetRenderer;

		}

	}

}
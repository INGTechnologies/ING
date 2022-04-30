
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

		/**IIDeviceContext
		 *	Constructors And Destructor
		 */
		IPipeline::IPipeline	(String name) :
			defaultRenderer(0),
			renderer(0),
			targetRenderer(0)
		{

			this->name = name;

			isRendering = false;

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
		void IPipeline::SetupCamera	(IDeviceContext* context, Camera* camera) {



		}

		void IPipeline::ClearRenderingData(Camera* camera) {



		}

		bool IPipeline::Render	(IDeviceContext* context) {

			BeginRender(context);

			EndRender(context);

			return true;
		}

		void IPipeline::BeginRender(IDeviceContext* context) {

			/* Set Renderer */
			renderer = targetRenderer;

			isRendering = true;

			for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() != this) {

					camera->SetRenderingPipeline(this);

					SetupCamera(context, camera);

				}

			}
		}

		void IPipeline::EndRender(IDeviceContext* context) {

			isRendering = false;
		}

	}

}

/**
 *	Include Header
 */
#include "Renderer.h"



/**
 *	Include Scene
 */
#include <ING/Rendering/Scene/Scene.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



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





namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			Renderer::Renderer()
			{



			}

			Renderer::~Renderer()
			{



			}



			/**
			 *	Release Methods
			 */
			void Renderer::Release()
			{

				IRenderer::Release();

			}



			/**
			 *	Methods
			 */
			void Renderer::Render(Camera* camera, IDeviceContext* context) {

				IRenderer::Render(camera, context);

				Rendering::Scene* renderingScene = camera->GetRenderingScene();

			}

		}

	}

}
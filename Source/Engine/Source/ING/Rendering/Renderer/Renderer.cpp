
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

		/**
		 *	Constructors And Destructor
		 */
		IRenderer::IRenderer()
		{



		}

		IRenderer::~IRenderer()
		{



		}



		/**
		 *	Release Methods
		 */
		void IRenderer::Release()
		{

			delete this;

		}



		/**
		 *	Methods
		 */
		void IRenderer::Render(Camera* camera, DeviceContext* context) {



		}

	}

}
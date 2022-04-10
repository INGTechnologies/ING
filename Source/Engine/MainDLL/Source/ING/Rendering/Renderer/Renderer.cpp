
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



/**
 *	Include Rendering Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



/**
 *	Include Rendering Drawable Filter
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>





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
		void IRenderer::RenderDrawables(Camera* camera, const std::string& filterName, const std::string& passName) {

			if (camera->GetRenderingScene() == 0) {

				Debug::Warning(String("Camera ") + String(camera) + String(" Do Not Have Any Rendering Scene"));

				return;
			}

			const std::vector<Layer*>& layerVector = camera->GetRenderingScene()->GetLayerVector();

			unsigned int layerVectorSize = layerVector.size();

			for (unsigned int i = 0; i < layerVectorSize; ++i) {

				Layer* layer = layerVector[i];

				unsigned int layerIndex = layer->GetIndex();

				IDrawableFilter* filter = layer->GetFilter(filterName);

				for (auto drawable : filter->GetDrawableArray()) {

					if(drawable->IsActive())
						RenderDrawable(camera, drawable, passName);

				}

			}

		}

		void IRenderer::RenderDrawable(Camera* camera, IDrawable* drawable, const std::string& passName) {

			drawable->Draw(camera, passName);

		}

	}

}
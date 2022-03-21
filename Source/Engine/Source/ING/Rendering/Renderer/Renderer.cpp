
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
 *	Include Rendering Drawable Category
 */
#include <ING/Rendering/Drawable/Category/Category.h>



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
		void IRenderer::RenderDrawables(Scene* scene, const std::string& categoryName, const std::string& passName) {

			const std::vector<Layer*>& layerVector = scene->GetLayerVector();

			unsigned int layerVectorSize = layerVector.size();

			for (unsigned int i = 0; i < layerVectorSize; ++i) {

				Layer* layer = layerVector[i];

				unsigned int layerIndex = layer->GetIndex();

				IDrawableCategory* category = layer->GetCategory(categoryName);

				for (auto drawable : category->GetDrawableList()) {

					if(drawable->IsActive())
						RenderDrawable(drawable, passName);

				}

			}

		}

		void IRenderer::RenderDrawable(IDrawable* drawable, const std::string& passName) {

			drawable->Draw(passName);

		}

	}

}
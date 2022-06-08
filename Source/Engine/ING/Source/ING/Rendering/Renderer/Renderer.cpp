
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

		ING_BEGIN_REFLECTED_CLASS
			(C_Renderer, Reflection::C_Object)

			ING_CLASS_CONSTRUCTOR
				(C_Renderer)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Renderer::Constructor() {



		}



		/**
		 *	Release Methods
		 */
		void C_Renderer::Release()
		{

			Reflection::C_Object::Release();

		}



		/**
		 *	Methods
		 */
		void C_Renderer::RenderDrawables(C_Camera* camera, const String& filterName, const String& passName) {

			if (camera->GetRenderingScene() == 0) {

				Debug::Warning(ToString("Camera ") + ToString(camera) + ToString(" Do Not Have Any Rendering Scene"));

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

		void C_Renderer::RenderDrawable(C_Camera* camera, C_Drawable* drawable, const String& passName) {

			drawable->Draw(camera, passName);

		}

	}

}
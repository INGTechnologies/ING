
/**
 * Include Header
 */
#include "Drawable.h"



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
 *	Include Rendering Drawable Filter
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Rendering Layer System
 */
#include <ING/Rendering/Layer/System/System.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>




namespace ING {

	namespace Rendering {

		ING_BEGIN_REFLECTED_CLASS
			(C_Drawable, Reflection::C_Object)

			ING_CLASS_CONSTRUCTOR
				(C_Drawable, LayerSystem*)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Drawable::Constructor(LayerSystem* system) {

			layer = 0;

			this->system = system;

			filterNameVector.resize(0);

			SetLayer(0);

		}



		/**
		 *	Release Methods
		 */
		void	C_Drawable::Release() {

			Reflection::C_Object::Release();

		}



		/**
		 *	Properties
		 */
		void	C_Drawable::SetLayer(unsigned int index) {

			if (system->GetLayerVector()[index] == 0) {

				return;

			}

			unsigned int filterCount = filterNameVector.size();

			for (unsigned int i = 0; i < filterCount; ++i) {

				IDrawableFilter* filter = layer->GetFilter(filterNameVector[i]);

				filter->RemoveDrawable(this);

			}

			layer = system->GetLayer(index);

			SetFilterNameVector(filterNameVector);

		}

		Layer*	C_Drawable::GetLayer	() {
			
			return layer;
		}

		void	C_Drawable::SetFilterNameVector(const std::vector<String>& filterNameVector) {

			unsigned int filterCount = filterNameVector.size();

#ifdef _DEBUG
			for (unsigned int i = 0; i < filterCount; ++i) {

				if (!system->IsHaveFilter(filterNameVector[i])) {

					Debug::Error(ToString("Filter With Name ") + ToString('"') + filterNameVector[i] + ToString('"') + ToString(" Not Found"));

					return;

				}

			}
#endif

			filterCount = this->filterNameVector.size();

			for (unsigned int i = 0; i < filterCount; ++i) {

				IDrawableFilter* filter = layer->GetFilter(this->filterNameVector[i]);

				filter->RemoveDrawable(this);

			}

			filterCount = filterNameVector.size();

			this->filterNameVector = filterNameVector;

			for (unsigned int i = 0; i < filterCount; ++i) {

				IDrawableFilter* filter = layer->GetFilter(filterNameVector[i]);

				filter->AddDrawable(this);

			}
		
		}

		void	C_Drawable::SetFilters(const std::vector<String>& filterNameVector) {

			SetFilterNameVector(filterNameVector);

		}



		/**
		 *	Methods
		 */
		void	C_Drawable::Draw (C_Camera* camera, const String& passName) {

			

		}

	}

}
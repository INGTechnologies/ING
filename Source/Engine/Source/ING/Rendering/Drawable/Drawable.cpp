
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
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDrawable::IDrawable() : layer(0) {

			filterNameVector.resize(0);

			SetLayer(0);

		}

		IDrawable::~IDrawable() {



		}



		/**
		 *	Release Methods
		 */
		void	IDrawable::Release() {

			delete this;

		}



		/**
		 *	Properties
		 */
		void	IDrawable::SetLayer(unsigned int index) {

			if (LayerManager::GetInstance()->GetLayerVector()[index] == 0) {

				return;

			}

			unsigned int filterCount = filterNameVector.size();

			for (unsigned int i = 0; i < filterCount; ++i) {

				IDrawableFilter* filter = layer->GetFilter(filterNameVector[i]);

				filter->RemoveDrawable(this);

			}

			layer = LayerManager::GetInstance()->GetLayer(index);

			SetFilterNameVector(filterNameVector);

		}

		Layer*	IDrawable::GetLayer	() {
			
			return layer;
		}

		void	IDrawable::SetFilterNameVector(const std::vector<std::string>& filterNameVector) {

			unsigned int filterCount = filterNameVector.size();

#ifdef _DEBUG
			for (unsigned int i = 0; i < filterCount; ++i) {

				if (!LayerManager::GetInstance()->IsHaveFilter(filterNameVector[i])) {

					Debug::Error(String("Filter With Name ") + String('"') + filterNameVector[i] + String('"') + String(" Not Found"));

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

		void	IDrawable::SetFilters(const std::vector<std::string>& filterNameVector) {

			SetFilterNameVector(filterNameVector);

		}



		/**
		 *	Methods
		 */
		void	IDrawable::Draw (Camera* camera, const std::string& passName) {

			

		}

	}

}
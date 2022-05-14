
/**
 *	Include Header
 */
#include "System.h"



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
		LayerSystem::LayerSystem() {

			layerVector.resize(MAX_LAYER_COUNT);

			unsigned int layerVectorSize = layerVector.size();

			for (unsigned int i = 0; i < layerVectorSize; ++i) {

				layerVector[i] = 0;

			}

			/* Create Categories */
			RecreateFilters({

				"Opaque",

				"Transparent",

				"UI",

				"Unlit"

			});



			/**
			 *	Create Layers
			 */
			Layer* DEFAULT_LAYER	= new Layer("Default", this);
			Layer* NO_RAYCAST_LAYER = new Layer("NoRayCast", this);



			/**
			 *	Add Layers
			 */
			SetLayer(DEFAULT_LAYER, 0);

			SetLayer(NO_RAYCAST_LAYER, 1);

		}

		LayerSystem::~LayerSystem() {



		}

		void LayerSystem::Release() {

			for (auto item : layerVector) {

				item->Release();

			}

			layerVector.clear();

			filterNameMap.clear();

			delete this;
		}



		/**
		 *	Properties
		 */
		void	LayerSystem::SetFilterNameMap(const std::vector<String>& filterNameVector) {

			std::unordered_map<String, bool> filterNameMap2;

			for (const String& filterName : filterNameVector) {

				filterNameMap2[filterName] = true;

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<String, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

					if (tl_name2FilterMap.find(filterName) == tl_name2FilterMap.end()) {

						layer->AddFilter(filterName);

					}

				}

			}

			for (auto& item : filterNameMap) {

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<String, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

					if (tl_name2FilterMap.find(item.first) != tl_name2FilterMap.end()
						&& filterNameMap2.find(item.first) == filterNameMap2.end()
					) {

						layer->RemoveFilter(item.first);

					}

				}

			}

			filterNameMap.clear();

			for (const String& filterName : filterNameVector) {

				filterNameMap[filterName] = true;

			}

		}



		/**
		 *	Methods
		 */
		void	LayerSystem::SetLayer		(Layer* layer, unsigned int index) {

			layer->index = index;
			layerVector[index] = layer;



			/* Update Layer Filter */
			for (auto& item : filterNameMap) {

				const std::unordered_map<String, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

				if (tl_name2FilterMap.find(item.first) == tl_name2FilterMap.end()) {

					layer->AddFilter(item.first);

				}

			}

		}

		Layer*	LayerSystem::GetLayer		(unsigned int index) {

			return layerVector[index];

		}

		void	LayerSystem::RemoveLayer	(unsigned int index) {

			delete layerVector[index];

			layerVector[index] = 0;

		}

		void	LayerSystem::RecreateFilters(const std::vector<String>& filterNameVector) {

			SetFilterNameMap(filterNameVector);

		}

	}
}

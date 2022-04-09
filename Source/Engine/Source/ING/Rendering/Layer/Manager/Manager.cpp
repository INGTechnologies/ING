
/**
 *	Include Header
 */
#include "Manager.h"



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
		 *	Layers
		 */
		static Layer DEFAULT_LAYER		("Default");
		static Layer NO_RAYCAST_LAYER	("NoRayCast");



		/**
		 *	Constructors And Destructor
		 */
		LayerManager::LayerManager() {

			Debug::Log("Start Creating Rendering::LayerManager");

			layerVector.resize(MAX_LAYER_COUNT);

			unsigned int layerVectorSize = layerVector.size();

			for (unsigned int i = 0; i < layerVectorSize; ++i) {

				layerVector[i] = 0;

			}

			Debug::Log("Rendering::LayerManager Created");

		}

		LayerManager::~LayerManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool LayerManager::Init() {

			Debug::Log("Start Initializing Rendering::LayerManager");

			/* Create Categories */
			RecreateFilters({

				"Opaque",

				"Transparent",

				"UI"

			});



			/**
			 *	Add Layers
			 */
			SetLayer(&DEFAULT_LAYER, 0);

			SetLayer(&NO_RAYCAST_LAYER, 1);

			Debug::Log("Rendering::LayerManager Initialized");

			return true;
		}

		bool LayerManager::Run() {

			Debug::Log("Start Running Rendering::LayerManager");

			return true;
		}

		bool LayerManager::Release() {

			Debug::Log("Start Releasing Rendering::LayerManager");

			filterNameMap.clear();

			delete this;

			Debug::Log("Finished Releasing Rendering::LayerManager");

			return true;
		}



		/**
		 *	Properties
		 */
		void	LayerManager::SetFilterNameMap(const std::vector<std::string>& filterNameVector) {

			std::unordered_map<std::string, bool> filterNameMap2;

			for (const std::string& filterName : filterNameVector) {

				filterNameMap2[filterName] = true;

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<std::string, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

					if (tl_name2FilterMap.find(filterName) == tl_name2FilterMap.end()) {

						layer->AddFilter(filterName);

					}

				}

			}

			for (auto& item : filterNameMap) {

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<std::string, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

					if (tl_name2FilterMap.find(item.first) != tl_name2FilterMap.end()
						&& filterNameMap2.find(item.first) == filterNameMap2.end()
					) {

						layer->RemoveFilter(item.first);

					}

				}

			}

			filterNameMap.clear();

			for (const std::string& filterName : filterNameVector) {

				filterNameMap[filterName] = true;

			}

		}



		/**
		 *	Methods
		 */
		void	LayerManager::SetLayer		(Layer* layer, unsigned int index) {

			layer->index = index;
			layerVector[index] = layer;



			/* Update Layer Filter */
			for (auto& item : filterNameMap) {

				const std::unordered_map<std::string, IDrawableFilter*>& tl_name2FilterMap = layer->GetName2DrawableFilterMap();

				if (tl_name2FilterMap.find(item.first) == tl_name2FilterMap.end()) {

					layer->AddFilter(item.first);

				}

			}

		}

		Layer*	LayerManager::GetLayer		(unsigned int index) {

			return layerVector[index];

		}

		void	LayerManager::RemoveLayer	(unsigned int index) {

			delete layerVector[index];

			layerVector[index] = 0;

		}

		void	LayerManager::RecreateFilters(const std::vector<std::string>& filterNameVector) {

			SetFilterNameMap(filterNameVector);

		}

	}
}

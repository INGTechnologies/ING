
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Layers
		 */
		static Layer DEFAULT_LAYER("Default");



		/**
		 *	Constructors And Destructor
		 */
		LayerManager::LayerManager() {

			layerVector.resize(MAX_LAYER_COUNT);

			unsigned int layerVectorSize = layerVector.size();

			for (unsigned int i = 0; i < layerVectorSize; ++i) {

				layerVector[i] = 0;

			}

		}

		LayerManager::~LayerManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool LayerManager::Init() {

			/* Create Categories */
			SetCategoryNameMap({

				"Opaque"

			});



			/**
			 *	Add Layers
			 */
			SetLayer(&DEFAULT_LAYER,0);

			return true;
		}

		bool LayerManager::Run() {



			return true;
		}

		bool LayerManager::Release() {

			categoryNameMap.clear();

			return true;
		}



		/**
		 *	Properties
		 */
		void	LayerManager::SetCategoryNameMap(const std::vector<std::string>& categoryNameVector) {

			std::unordered_map<std::string, bool> categoryNameMap2;

			for (const std::string& categoryName : categoryNameVector) {

				categoryNameMap2[categoryName] = true;

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<std::string, IDrawableCategory*>& tl_name2CategoryMap = layer->GetName2DrawableCategoryMap();

					if (tl_name2CategoryMap.find(categoryName) == tl_name2CategoryMap.end()) {

						layer->AddCategory(categoryName);

					}

				}

			}

			for (auto& item : categoryNameMap) {

				for (Layer* layer : layerVector) {

					if (layer == 0) { continue; }

					const std::unordered_map<std::string, IDrawableCategory*>& tl_name2CategoryMap = layer->GetName2DrawableCategoryMap();

					if (tl_name2CategoryMap.find(item.first) != tl_name2CategoryMap.end()
						&& categoryNameMap2.find(item.first) == categoryNameMap2.end()
					) {

						layer->RemoveCategory(item.first);

					}

				}

			}

		}



		/**
		 *	Methods
		 */
		void	LayerManager::SetLayer		(Layer* layer, unsigned int index) {

			layer->index = index;

			layerVector[index] = layer;

		}

		Layer*	LayerManager::GetLayer		(unsigned int index) {

			return layerVector[index];

		}

		void	LayerManager::RemoveLayer	(unsigned int index) {

			delete layerVector[index];

			layerVector[index] = 0;

		}

	}
}


/**
 *	Include Header
 */
#include "Scene.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



/**
 *	Include Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Drawable Category
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include BitSet
 */
#include <bitset>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Scene::Scene(std::string name)
		{

			this->name = name;

			layerMask = 0;

			SceneManager::GetInstance()->AddScene(this);

		}

		Scene::~Scene()
		{



		}



		/**
		 *	Release Methods
		 */
		void Scene::Release()
		{

			SceneManager::GetInstance()->RemoveScene(this);

			delete this;

		}



		/**
		 *	Properties
		 */
		void Scene::SetLayerMask(Mask64 layerMask) {
			
			this->layerMask = layerMask;

			unsigned int layerCount = 0;

			std::bitset<MAX_LAYER_COUNT> maskBitSet = layerMask;

			for (unsigned int i = 0; i < MAX_LAYER_COUNT; ++i) {

				if(maskBitSet[i] == 1)
					++layerCount;

			}

			layerVector.resize(layerCount);

			for (unsigned int i = 0; i < layerCount; ++i) {

				if (maskBitSet[i] == 1) {

					Rendering::LayerManager* layerManager = Rendering::LayerManager::GetInstance();
					layerVector[i] = LayerManager::GetInstance()->GetLayer(i);

				}

			}
		
		}

		void Scene::ContainLayers(const std::vector<unsigned int>& indices) {

			Mask64 layerMask = 0;

			unsigned int count = indices.size();

			for (unsigned int i = 0; i < count; ++i) {

				layerMask |= 1 << indices[i];

			}

			SetLayerMask(layerMask);

		}

	}

}
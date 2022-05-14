
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
 *	Include Layer System
 */
#include <ING/Rendering/Layer/System/System.h>



/**
 *	Include Drawable Category
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include BitSet
 */
#include <bitset>



/**
 *	Include Rendering Scene System
 */
#include <ING/Rendering/Scene/System/System.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Scene::Scene(String name, SceneSystem* system) :
			name(name),
			system(system)
		{

			layerMask = 0;

			system->AddScene(this);

		}

		Scene::~Scene()
		{



		}



		/**
		 *	Release Methods
		 */
		void Scene::Release()
		{

			system->RemoveScene(this);

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

					layerVector[i] = system->GetLayerSystem()->GetLayer(i);

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
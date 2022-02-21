#pragma once

/**
 *	Include Header
 */
#include "Repository.h"



/**
 *	Include Entity
 */
#include <ING/ECS/Entity/Entity.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Constructor And Destructor
		 */
		Repository::Repository() {

			isActive = true;

		}

		Repository::~Repository() {

			componentSystemTypeId2ComponentSystemMap.clear();
			componentTypeId2ComponentSystemMap.clear();

		}



		/**
		 *	Properties
		 */
		void				Repository::SetActive(bool isActive) {

			this->isActive = isActive;

		}



		/**
		 *	Methods
		 */
		template<class TComponentSystem>
		TComponentSystem*	Repository::CreateComponentSystem() {

			TComponentSystem* componentSystem = new TComponentSystem(this);

			componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()] = componentSystem;
			componentTypeId2ComponentSystemMap[componentSystem->GetComponentTypeId()] = componentSystem;

			return componentSystem;

		}

		template<class TComponentSystem>
		TComponentSystem*	Repository::GetComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			return componentSystem;

		}

		template<class T>
		IComponentSystem*	Repository::GetComponentSystemFromComponentType() {

			IComponentSystem* componentSystem = componentSystemTypeId2ComponentSystemMap[typeid(T).name()];

			return componentSystem;

		}

		template<typename TComponentSystem>
		void				Repository::ReleaseComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			componentTypeId2ComponentSystemMap.erase(componentSystem->GetComponentTypeId());

			componentSystem->Release();

			componentSystemTypeId2ComponentSystemMap.erase(typeid(TComponentSystem).name());

		}

		Entity*				Repository::CreateEntity() {
		
			Entity* result = new Entity(this);

			return result;		
		}

	}

}
#pragma once

/**
 *	Include Header
 */
#include "Repository.h"



/**
 *	Include Entity
 */
#include <ING/ECS/Core/Entity/Entity.h>



/**
 *	Include Repository Manager
 */
#include "Manager/Manager.h"



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

			node = RepositoryManager::GetInstance()->AddRepository(this);

		}

		Repository::~Repository() {

			componentSystemTypeId2ComponentSystemMap.clear();
			componentTypeId2ComponentSystemMap.clear();

			RepositoryManager::GetInstance()->RemoveRepository(node);

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

		void				Repository::ReleaseEntity(Entity* entity) {

			entity->Release();

		}



		/**
		 *	Event Methods
		 */
		void				Repository::Update() {

			for (auto& item : componentSystemTypeId2ComponentSystemMap) {

				IComponentSystem* isystem = item.second;

				isystem->Update();

			}

		}

	}

}
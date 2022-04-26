
/**
 *	Include ECS
 */
#include "Repository.h"



/**
 *	Include Repository Manager
 */
#include "Manager/Manager.h"



/**
 *	Include Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include Entity
 */
#include <ING/ECS/Entity/Entity.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructor And Destructor
		 */
		Repository::Repository() :
			node(0)
		{

			isActive = true;

			node = RepositoryManager::GetInstance()->AddRepository(this);

		}

		Repository::~Repository() {



		}



		/**
		 *	Release Methods
		 */
		void Repository::Release() {

			unsigned int componentSystemCount = componentSystemVector.size();

			for (unsigned int i = 0; i < componentSystemCount; ++i) {

				componentSystemVector[i]->Release();

			}

			componentSystemTypeId2ComponentSystemMap.clear();
			componentTypeId2ComponentSystemMap.clear();

			RepositoryManager::GetInstance()->RemoveRepository(node);

			delete this;
		
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
		Entity*				Repository::CreateEntity() {
		
			Entity* result = new Entity(this);

			return result;		
		}

		Entity*				Repository::CreateEntity(const std::vector<IComponentSystem*> systemVector) {

			Entity* result = new Entity(this);

			for (auto system : systemVector) {

				system->AddComponent(result);

			}

			return result;
		}

		void				Repository::ReleaseEntity(Entity* entity) {

			entity->Release();

		}



		/**
		 *	Event Methods
		 */
		void				Repository::PreUpdate() {

			for (auto& item : componentSystemVector) {

				item->PreUpdate();

			}

		}

		void				Repository::Update() {

			for (auto& item : componentSystemVector) {

				item->Update();

			}

		}

		void				Repository::LateUpdate() {

			for (auto& item : componentSystemVector) {

				item->LateUpdate();

			}

		}

		void				Repository::PreRender() {

			for (auto& item : componentSystemVector) {

				item->PreRender();

			}

		}

		void				Repository::Render() {

			for (auto& item : componentSystemVector) {

				item->Render();

			}

		}

		void				Repository::LateRender() {

			for (auto& item : componentSystemVector) {

				item->LateRender();

			}

		}

	}

}
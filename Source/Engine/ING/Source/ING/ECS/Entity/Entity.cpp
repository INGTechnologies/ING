
/**
 *	Include Header
 */
#include "Entity.h"



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Entity::Entity	(Repository* repository) {

			this->repository = repository;

		}

		Entity::~Entity	() {



		}



		/**
		 *	Release Methods
		 */
		void Entity::Release() {

			for (auto it = componentMap.cbegin(); it != componentMap.cend();)
			{

				IComponentPtr componentPtr = it->second;

				IComponentSystem* componentSystem = componentPtr.GetIComponentSystem();

				++it;

				componentSystem->RemoveComponent(this);

			}

			delete this;
		}

	}

}
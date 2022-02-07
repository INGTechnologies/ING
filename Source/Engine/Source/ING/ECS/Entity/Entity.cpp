
/**
 *	Include Header
 */
#include "Entity.h"



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Entity::Entity() {



		}

		Entity::~Entity() {



		}



		/**
		 *	Release Methods
		 */
		void Entity::Release() {

			delete this;

		}

	}

}
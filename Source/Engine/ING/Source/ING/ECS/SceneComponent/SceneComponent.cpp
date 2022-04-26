
/**
 *	Include Header
 */
#include "SceneComponent.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		SceneComponent::SceneComponent() {



		}

		SceneComponent::~SceneComponent() {



		}



		/**
		 *	Release Method
		 */
		void SceneComponent::Release() {

			delete this;

		}

	}

}
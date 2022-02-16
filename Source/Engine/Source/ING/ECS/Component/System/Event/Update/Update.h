#pragma once



/**
 *	Include Component System Event
 */
#include <ING/ECS/Component/System/Event/Event.h>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		/**
		 *	Main Class
		 */
		template<typename T, class TComponentSystem>
		class ComponentSystemUpdateEvent :
			public ComponentSystemEvent<T, TComponentSystem>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentSystemUpdateEvent(TComponentSystem* componentSystem) : ComponentSystemEvent<T, TComponentSystem>(componentSystem) {



			}

			~ComponentSystemUpdateEvent() {



			}



			/**
			 *	Name
			 */
		public:
			virtual std::string GetName() override;

		};

	}

}



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Name
		 */
		template<typename T, class TComponentSystem>
		std::string ComponentSystemUpdateEvent<T,TComponentSystem>::GetName() {

			return "UPDATE";

		}

	}

}
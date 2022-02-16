#pragma once



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		/**
		 *	Interface Class
		 */
		class IComponentSystemEvent : public Event {

			/**
			 *	Constructor And Destructor
			 */
		public:
			IComponentSystemEvent() {



			}

			~IComponentSystemEvent() {



			}

		};



		/**
		 *	Main Class
		 */
		template<typename T, class TComponentSystem>
		class ComponentSystemEvent :
			public IComponentSystemEvent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentSystemEvent(TComponentSystem* componentSystem) {

				this->componentSystem = componentSystem;

			}

			~ComponentSystemEvent() {



			}



			/**
			 *	Properties
			 */
		private:
			TComponentSystem* componentSystem;

		public:
			TComponentSystem* GetComponentSystem() { return componentSystem; }

		};

	}

}



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {



	}

}
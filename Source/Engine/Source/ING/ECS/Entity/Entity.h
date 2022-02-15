#pragma once



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Define And Declares Classes, Structs,...
 */
namespace ING {

	namespace ECS {

		class IComponentPtr;

		template<typename T, class TComponentSystem>
		class ComponentPtr;

		template<typename T, class TComponentSystem>
		class ComponentSystem;



		/**
		 *	Main Class
		 */
		struct Entity
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Entity  () {



			}

			~Entity () {



			}



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;
			}



			/**
			 *	Properties
			 */
		private:
			std::map<std::string, IComponentPtr>	componentMap;

		public:
			std::map<std::string, IComponentPtr>&	GetComponentMap() {

				return componentMap;

			}



			/**
			 *	Methods
			 */
		public:
			template<typename T, class TComponentSystem>
			void								AddComponent(ComponentPtr<T, TComponentSystem> componentPtr);

			template<typename T, class TComponentSystem>
			ComponentPtr<T, TComponentSystem>	GetComponent();

			template<typename T>
			void								RemoveComponent();

		};

	}

}



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Methods
		 */
		template<typename T, class TComponentSystem>
		void								Entity::AddComponent(ComponentPtr<T, TComponentSystem> componentPtr) {

			componentMap[typeid(T).name()] = componentPtr;

		}

		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	Entity::GetComponent() {

			return ComponentPtr<T, TComponentSystem>(componentMap[typeid(T).name()]);

		}

		template<typename T>
		void								Entity::RemoveComponent() {

			componentMap.erase(typeid(T).name());

		}

	}

}
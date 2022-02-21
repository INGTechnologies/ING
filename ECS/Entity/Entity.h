#pragma once

/**
 *	Include ECS Entry Point
 */
#include <ING/ECS/EntryPoint/EntryPoint.h>



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
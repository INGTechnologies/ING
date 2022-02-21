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

		class Repository;



		/**
		 *	Main Class
		 */
		struct Entity
		{
			/**
			 *	Friend Class
			 */
			friend class Repository;



			/**
			 *	Constructors And Destructor
			 */
		protected:
			Entity	(Repository* repository);

		public:
			~Entity	();



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

			Repository* repository;

		public:
			std::map<std::string, IComponentPtr>&	GetComponentMap() {

				return componentMap;

			}

			Repository*								GetRepository() { return repository; }



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
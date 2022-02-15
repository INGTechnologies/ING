#pragma once



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/ECS/Component/Id/Id.h>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		class Entity;

		class Repository;

		template<typename T, class TComponentSystem>
		class ComponentPtr;

		template<typename T>
		class ComponentArray;



		/**
		 *	Interface Class
		 */
		class IComponentSystem {

			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};



		/**
		 *	Main Class
		 */
		template<typename T, class TComponentSystem>
		class ComponentSystem :
			public IComponentSystem
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentSystem(Repository* repository) {

				this->repository = repository;

			}

			~ComponentSystem() {

				array.Clear();

				idGenerator.ClearIds();

			}



			/**
			 *	Properties
			 */
		private:
			ComponentArray<T>			array;

			IdGenerator					idGenerator;

			Repository* repository;

		public:
			ComponentArray<T>& GetArray() { return array; }

			IdGenerator& GetIdGenerator() { return idGenerator; }

			Repository* GetRepository() { return repository; }



			/**
			 *	Methods
			 */
		public:
			ComponentPtr<T, TComponentSystem>	AddComponent(Entity* entity, T& component);

			ComponentPtr<T, TComponentSystem>	AddComponent(Entity* entity);

			T& GetComponent(Entity* entity);

			T& GetComponentFromId(ComponentId id);

			void								RemoveComponent(Entity* entity);

			void								Foreach(void (*callback)(T& component));

			std::string							GetComponentTypeId();

		};



		/**
		 *	Define Macros
		 */
#define ECS_COMPONENT_SYSTEM_CLASS(T, TComponentSystem)\
		class TComponentSystem : public ING::ECS::ComponentSystem<T, TComponentSystem>

#define ECS_COMPONENT_SYSTEM_CONSTRUCTOR(T, TComponentSystem)\
		TComponentSystem(ING::ECS::Repository* repository) : ING::ECS::ComponentSystem<T, TComponentSystem>(repository)

#define ECS_COMPONENT_SYSTEM_DESTRUCTOR(T, TComponentSystem)\
		~TComponentSystem()

	}

}



/**
 *	Include ECS Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include ECS Component Array
 */
#include <ING/ECS/Component/Array/Array.h>



/**
 *	Include ECS Component Ptr
 */
#include <ING/ECS/Component/Ptr/Ptr.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {
		
		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity, T& component)	{

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt32();

			array.Add(component, id);

			result.SetId(id);
			result.SetRepository(repository);

			return result;

		}

		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity) {

			ComponentPtr<T, TComponentSystem> result;

			T component;

			ComponentId id = idGenerator.GenUInt32();

			array.Add(component, id);

			result.SetId(id);
			result.SetRepository(repository);

			return result;

		}

		template<typename T, class TComponentSystem>
		T&							ComponentSystem<T, TComponentSystem>::GetComponent	(Entity* entity) {

			T component;

			//ComponentId id = idGenerator.GenUInt32();

			//array.Get(id);

			return component;

		}

		template<typename T, class TComponentSystem>
		T&							ComponentSystem<T, TComponentSystem>::GetComponentFromId(ComponentId id) {

			T& component = array.Get(id);

			return component;

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::RemoveComponent	(Entity* entity)	{

				

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach			(void (*callback)(T& component)){
			
			for (unsigned int index = 0; index < array.GetCount(); ++index) {

				callback(array.GetPData()[index]);

			}
			
		}

		template<typename T, class TComponentSystem>
		std::string					ComponentSystem<T, TComponentSystem>::GetComponentTypeId() {

			return typeid(T).name();

		}

	}

}
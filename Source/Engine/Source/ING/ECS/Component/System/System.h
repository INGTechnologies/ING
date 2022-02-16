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
 *	Include Event Storage
 */
#include <ING/Event/Storage/Storage.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



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

		template<typename T, class TComponentSystem>
		class ComponentSystemUpdateEvent;



		/**
		 *	Interface Class
		 */
		class IComponentSystem : public EventStorage {

			/**
			 *	Constructor
			 */
		public:
			IComponentSystem() {



			}



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual void Init() {



			}

			virtual void Release() {

				RELEASE_EVENT_STORAGE();

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
			ComponentSystem(Repository* repository);

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
			ComponentArray<T>&	GetArray		() { return array;			}

			IdGenerator&		GetIdGenerator	() { return idGenerator;	}

			Repository*			GetRepository	() { return repository;		}



			/**
			 *	Methods
			 */
		public:
			ComponentPtr<T, TComponentSystem>	AddComponent				(Entity* entity, T& component);

			ComponentPtr<T, TComponentSystem>	AddComponent				(Entity* entity);

			ComponentPtr<T, TComponentSystem>	GetComponent				(Entity* entity);

			T&									GetComponentFromId			(ComponentId id); 

			T*									GetComponentDataPtrFromId	(ComponentId id);

			void								RemoveComponent				(Entity* entity);

			void								Foreach						(void (*callback)(T& component));

			std::string							GetComponentTypeId			();

		};

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
 *	Include ECS Entity
 */
#include <ING/ECS/Entity/Entity.h>



/**
 *	Include ECS Component System Events
 */
#include <ING/ECS/Component/System/Event/Update/Update.h>

#include <ING/ECS/Component/System/Event/Awake/Awake.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T, class TComponentSystem>
		ComponentSystem<T,TComponentSystem>::ComponentSystem(Repository* repository) : IComponentSystem() {

			this->repository = repository;



			/**
			 *	Add Events
			 */
			//AddEvent(new ComponentSystemAwakeEvent	<T, TComponentSystem> ());

			AddEvent(new ComponentSystemUpdateEvent	<T, TComponentSystem>((TComponentSystem*)this));

			AddEvent(new ComponentSystemAwakeEvent	<T, TComponentSystem>((TComponentSystem*)this));

		}


		
		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity, T& component)	{

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt32();

			array.Add(component, id);

			result.SetId(id);
			result.SetRepository(repository);

			entity->AddComponent<T, TComponentSystem>(result);

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

			entity->AddComponent<T, TComponentSystem>(result);

			return result;

		}

		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::GetComponent	(Entity* entity) {

			ComponentPtr<T, TComponentSystem> componentPtr = entity->GetComponent<T, TComponentSystem>();

			return componentPtr;

		}

		template<typename T, class TComponentSystem>
		T&							ComponentSystem<T, TComponentSystem>::GetComponentFromId(ComponentId id) {

			T& component = array.Get(id);

			return component;

		}

		template<typename T, class TComponentSystem>
		T*							ComponentSystem<T, TComponentSystem>::GetComponentDataPtrFromId(ComponentId id) {

			T* componentDataPtr = array.GetDataPtr(id);

			return componentDataPtr;

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::RemoveComponent	(Entity* entity)	{

			ComponentId id = GetComponent(entity).GetId();

			array.Erase(id);

			entity->RemoveComponent<T>();

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
#pragma once

/**
 *	Include Header
 */
#include "System.h"



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
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T, class TComponentSystem>
		ComponentSystem<T,TComponentSystem>::ComponentSystem(Repository* repository) : IComponentSystem() {

			this->repository = repository;

		}



		template<typename T, class TComponentSystem>
		ComponentSystem<T, TComponentSystem>::~ComponentSystem() {

			array.Clear();

			isStartedArray.Clear();

			idGenerator.ClearIds();

		}



		/**
		 *	Methods
		 */
		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity, T& component)	{

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt32();

			array.Add(component, id);

			bool isStarted = false;
			isStartedArray.Add(isStarted, id);

			result.SetId(id);
			result.SetRepository(repository);

			entity->AddComponent<T, TComponentSystem>(result);

			Awake(result);

			return result;

		}

		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity) {

			T component;

			return AddComponent(entity, component);

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

			isStartedArray.Erase(id);

			entity->RemoveComponent<T>();

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach			(void (*callback)(T& component)){
			
			T* pData = array.GetPData();

			unsigned int count = array.GetCount();

			for (unsigned int index = 0; index < count; ++index) {

				callback(pData[index]);

			}
			
		}

		template<typename T, class TComponentSystem>
		std::string					ComponentSystem<T, TComponentSystem>::GetComponentTypeId() {

			return typeid(T).name();

		}



		/**
		 *	Event Methods
		 */
		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Update() {

			/* Check And Start Component Which Is Not Started */
			bool* isStartedArrayPData = isStartedArray.GetPData();

			unsigned int count = isStartedArray.GetCount();

			for (unsigned int index = 0; index < count; ++index) {

				if (!isStartedArrayPData[index]) {

					isStartedArrayPData[index] = true;

					ComponentId id = isStartedArray.GetIndex2IdMap()[index];

					ComponentPtr<T, TComponentSystem> componentPtr;

					componentPtr.SetId(id);

					componentPtr.SetRepository(repository);

					Start(componentPtr);

				}

			}

		}

	}

}
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

			idGenerator.ClearIds();

		}



		/**
		 *	Methods
		 */
		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity, T& component)	{

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt16();

			array.Add(component, id);

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
		T&							ComponentSystem<T, TComponentSystem>::GetComponentFromPtr(ComponentPtr<T, TComponentSystem>& ptr) {

			T& component = array.Get(ptr.GetId());

			return component;

		}

		template<typename T, class TComponentSystem>
		T*							ComponentSystem<T, TComponentSystem>::GetComponentDataPtrFromPtr(ComponentPtr<T, TComponentSystem>& ptr) {

			T* componentDataPtr = array.GetDataPtr(ptr.GetId());

			return componentDataPtr;

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::RemoveComponent	(Entity* entity)	{

			ComponentId id = GetComponent(entity).GetId();

			array.Erase(id);

			idGenerator.RemoveUInt16Id(id);

			entity->RemoveComponent<T>();

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach			(void (*callback)(T& component)){

			std::vector<SmartArrayBlock<T>*> arrayBlockVector = array.GetBlockVector();

			for (SmartArrayBlock<T>* block : arrayBlockVector) {

				for (unsigned int index = 0; index < block->filledCount; ++index) {

					callback(block->pData[index]);

				}

			}
			
		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach(void (*callback)(T& component, ECS::ComponentPtr<T, TComponentSystem>& ptr)) {

			std::vector<SmartArrayBlock<T>*> arrayBlockVector = array.GetBlockVector();

			for (SmartArrayBlock<T>* block : arrayBlockVector) {

				for (unsigned int index = 0; index < block->filledCount; ++index) {

					ECS::ComponentPtr<T, TComponentSystem> ptr;

					ptr.SetId(block->index2IdMap[index]);

					ptr.SetRepository(repository);

					callback(block->pData[index], ptr);

				}

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

			

		}

	}

}
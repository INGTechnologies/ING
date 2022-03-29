#pragma once

/**
 *	Include Header
 */
#include "System.h"



/**
 *	Include ECS Component
 */
#include <ING/ECS/Core/Component/Component.h>



/**
 *	Include ECS Component Ptr
 */
#include <ING/ECS/Core/Component/Ptr/Ptr.h>



/**
 *	Include ECS Entity
 */
#include <ING/ECS/Core/Entity/Entity.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T, class TComponentSystem>
		ComponentSystem<T,TComponentSystem>::ComponentSystem(Repository* repository) : IComponentSystem() {

			this->repository = repository;

			//array.callDestructor = true;

		}



		template<typename T, class TComponentSystem>
		ComponentSystem<T, TComponentSystem>::~ComponentSystem() {

			array.Clear();

			idGenerator.ClearIds();

		}



		/**
		 *	Methods
		 */
		void	IComponentSystem::RemoveComponent(Entity* entity) {



		}



		/**
		 *	Methods
		 */
		template<typename T, class TComponentSystem>
		void	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity) {

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt64();

			array.Add(T(entity), id);

			result.SetId(id);
			result.SetIComponentSystem(this);

			entity->AddComponent<T, TComponentSystem>(result);

			Awake(result);

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

			ComponentPtr<T, TComponentSystem> ptr = GetComponent(entity);

			ComponentId id = ptr.GetId();

			IDestroy(ptr);

			array.Erase(id);

			idGenerator.RemoveUInt64Id(id);

			entity->RemoveComponent<T>();

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach			(void (*callback)(T& component)){

			for (unsigned int index = 0; index < array.GetFilledCount(); ++index) {

				callback(array.GetPData()[index]);

			}
			
		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Foreach(void (*callback)(T& component, ECS::ComponentPtr<T, TComponentSystem>& ptr)) {

			for (unsigned int index = 0; index < array.GetFilledCount(); ++index) {

				ECS::ComponentPtr<T, TComponentSystem> ptr;

				ptr.SetId(array.Index2Id(index));

				ptr.SetIComponentSystem(this);

				callback(array.GetPData()[index], ptr);

			}

		}

		template<typename T, class TComponentSystem>
		std::string					ComponentSystem<T, TComponentSystem>::GetComponentTypeId() {

			return typeid(T).name();

		}

		template<typename T, class TComponentSystem>
		T*							ComponentSystem<T, TComponentSystem>::begin() {

			return array.GetPData();

		}

		template<typename T, class TComponentSystem>
		T*							ComponentSystem<T, TComponentSystem>::end() {

			return begin() + array.GetFilledCount();

		}



		/**
		 *	Event Methods
		 */
		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::IAwake(IComponentPtr componentPtr) {

			ComponentPtr<T, TComponentSystem> tPtr;

			tPtr.SetId(componentPtr.GetId());
			tPtr.SetIComponentSystem(componentPtr.GetIComponentSystem());

			Awake(tPtr);

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::IStart(IComponentPtr componentPtr) {

			ComponentPtr<T, TComponentSystem> tPtr;

			tPtr.SetId(componentPtr.GetId());
			tPtr.SetIComponentSystem(componentPtr.GetIComponentSystem());

			Start(tPtr);

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::Update() {

			

		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::PreUpdate() {



		}

		template<typename T, class TComponentSystem>
		void						ComponentSystem<T, TComponentSystem>::IDestroy(IComponentPtr componentPtr) {

			ComponentPtr<T, TComponentSystem> tPtr;

			tPtr.SetId(componentPtr.GetId());
			tPtr.SetIComponentSystem(componentPtr.GetIComponentSystem());

			Destroy(tPtr);

		}

	}

}
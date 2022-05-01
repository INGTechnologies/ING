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
 *	Include Id
 */
#include <ING/ECS/Component/Ptr/Ptr.h>



/**
 *	Include Entity
 */
#include <ING/ECS/Entity/Entity.h>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		struct Entity;

		class Repository;

		template<typename T, class TComponentSystem>
		class ComponentPtr;

		template<typename T, class TComponentSystem>
		class ComponentSystemUpdateEvent;



		/**
		 *	Interface Class
		 */
		class ING_API IComponentSystem{

		public:
			friend class Repository;



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

				delete this;

			}



			/**
			 *	Properties
			 */
		private:
			unsigned int index;

		public:
			unsigned int GetIndex() { return index; }



			/**
			 *	Methods
			 */
		public:
			virtual void RemoveComponent(Entity* entity) {}
			virtual void AddComponent(Entity* entity) {}



			/**
			 *	Event Methods
			 */
		public:
			virtual void IAwake(IComponentPtr componentPtr) {
			
				
			
			}

			virtual void IStart(IComponentPtr componentPtr) {
			
				
			
			}

			virtual void PreUpdate() {



			}

			virtual void Update() {



			}

			virtual void LateUpdate() {



			}

			virtual void PreRender() {



			}

			virtual void Render() {



			}

			virtual void LateRender() {



			}

			virtual void IDestroy(IComponentPtr componentPtr) {



			}

			virtual void IAfterDestroy() {



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
			 *	Friend Class
			 */
			friend class Repository;



			/**
			 *	Constructors And Destructor
			 */
		protected:
			ComponentSystem		(Repository* repository);

		public:
			~ComponentSystem	();



			/**
			 *	Properties
			 */
		protected:
			SmartArray<T>			array;

			String				typeId;

		public:
			IdGenerator				idGenerator;

			Repository*				repository;

		public:
			SmartArray<T>&			GetArray			() { return array;			}

			String				GetComponentTypeId	() { return typeId; }

			IdGenerator&			GetIdGenerator		() { return idGenerator;	}

			Repository*				GetRepository		() { return repository;		}



			/**
			 *	Methods
			 */
		public:
			virtual void						AddComponent				(Entity* entity) override;

			ComponentPtr<T, TComponentSystem>	GetComponent				(Entity* entity);

			T&									GetComponentFromPtr			(ComponentPtr<T, TComponentSystem>& ptr); 

			T*									GetComponentDataPtrFromPtr	(ComponentPtr<T, TComponentSystem>& ptr);

			virtual void						RemoveComponent				(Entity* entity) override;

			void								Foreach						(void (*callback)(T& component));
			void								Foreach						(void (*callback)(T& component, ECS::ComponentPtr<T, TComponentSystem>& ptr));

			T*									begin						();
			T*									end							();



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake	(ComponentPtr<T, TComponentSystem> componentPtr)	{ }

			virtual void Start  (ComponentPtr<T, TComponentSystem> componentPtr)	{ }

			virtual void IAwake	(IComponentPtr componentPtr)	override;

			virtual void IStart	(IComponentPtr componentPtr)	override;

			virtual void Update ()								override;

			virtual void PreUpdate()							override;

			virtual void Destroy(ComponentPtr<T, TComponentSystem> componentPtr) { }

			virtual void IDestroy(IComponentPtr componentPtr)	override;



			/**
			 *	Operators
			 */
		public:

		};

	}

}



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T, class TComponentSystem>
		ComponentSystem<T,TComponentSystem>::ComponentSystem(Repository* repository) : IComponentSystem() {

			this->repository = repository;

			typeId = typeid(T).name();

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
		void	ComponentSystem<T, TComponentSystem>::AddComponent	(Entity* entity) {

			ComponentPtr<T, TComponentSystem> result;

			ComponentId id = idGenerator.GenUInt64();

			array.Add(T(entity, this, id), id);

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

			IAfterDestroy();

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

		//template<typename T, class TComponentSystem>
		//String					ComponentSystem<T, TComponentSystem>::GetComponentTypeId() {

		//	return typeid(T).name();

		//}

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



/**
 *	Define Macros
 */
#define ECS_COMPONENT_SYSTEM(TComponentSystem, T)\
class TComponentSystem : public ING::ECS::ComponentSystem<T, TComponentSystem> {\
\
public:\
	friend class ING::ECS::Repository;\
\
protected:\
	TComponentSystem(ING::ECS::Repository* repository) : ING::ECS::ComponentSystem<T, TComponentSystem>(repository) {}\

#define ECS_FOREACH_COMPONENT(T, TComponentSystem, itemName,system, callback)\
{\
\
for (unsigned int index = 0; index < (system)->GetArray().GetFilledCount(); ++index) {\
\
ECS::ComponentPtr<T, TComponentSystem> itemName;\
\
itemName.SetId((system)->GetArray().Index2Id(index));\
\
itemName.SetIComponentSystem(system);\
\
callback\
\
}\
\
}
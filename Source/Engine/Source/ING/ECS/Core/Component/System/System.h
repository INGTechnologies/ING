#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/ECS/Core/Component/Id/Id.h>



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
		class IComponentSystem{

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
			virtual void RemoveComponent(Entity* entity);
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

		public:
			IdGenerator				idGenerator;

			Repository*				repository;

		public:
			SmartArray<T>&			GetArray			() { return array;			}

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

			std::string							GetComponentTypeId			();

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
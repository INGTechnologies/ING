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
 *	Include Id
 */
#include <ING/ECS/Component/Id/Id.h>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		struct Entity;

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
		class IComponentSystem{

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



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake	(ComponentPtr<T, TComponentSystem> componentPtr)	{ }

			virtual void Start  (ComponentPtr<T, TComponentSystem> componentPtr)	{ }

			virtual void Update ()													{ }

		};

	}

}
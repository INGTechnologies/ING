#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ECS Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include ECS Component Array
 */
#include <ING/ECS/Component/Array/Array.h>



namespace ING {

	namespace ECS {

		class Entity;



		class IComponentSystem {

			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};



		template<typename T>
		class ComponentSystem : 
			public IComponentSystem,
			public Singleton<T>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentSystem() {



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

		public:
			ComponentArray<T>&			GetArray		()					{ return array; }

			IdGenerator&				GetIdGenerator	()					{ return idGenerator;}



			/**
			 *	Methods
			 */
		public:
			ComponentId					AddComponent	(Entity* entity, T& component)	{

				ComponentId id = idGenerator.GenUInt32();

				array.Add(component, id);

				return id;

			}

			ComponentId					AddComponent	(Entity* entity) {

				T component;

				ComponentId id = idGenerator.GenUInt32();

				array.Add(component, id);

				return id;

			}

			T&							GetComponent	(Entity* entity) {

				T component;

				//ComponentId id = idGenerator.GenUInt32();

				//array.Get(id);

				return component;

			}

			void						RemoveComponent	(Entity* entity)	{

				

			}

			void						Foreach			(void (*callback)(T& component)){
			
				for (unsigned int index = 0; index < array.GetCount(); ++index) {

					callback(array.GetPData()[index]);

				}
			
			}

		};

	}

}
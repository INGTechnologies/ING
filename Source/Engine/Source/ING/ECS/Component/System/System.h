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
		class ComponentSystem : public IComponentSystem
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentSystem() {



			}

			~ComponentSystem() {

				array.Clear();

			}



			/**
			 *	Properties
			 */
		private:
			ComponentArray<T>			array;

		public:
			ComponentArray<T>&			GetArray		()					{ return array; }



			/**
			 *	Methods
			 */
		public:
			void						AddComponent	(Entity* entity)	{

				T component;

				array.Add(component);

			}

			void						RemoveComponent	(Entity* entity)	{

				

			}

		};

	}

}
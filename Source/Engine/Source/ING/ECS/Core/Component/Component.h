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



namespace ING {

	namespace ECS {

		class Entity;

		class IComponentSystem;



		struct Component
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Component(
				Entity* entity,
				IComponentSystem* system,
				ComponentId id
			) :
				entity(entity),
				system(system),
				id(id)
			{}

			~Component() {}



			/**
			 *	Properties
			 */
		protected:
			Entity* entity;
			IComponentSystem* system;
			ComponentId id;

		public:
			Entity* GetEntity () { return entity; }
			IComponentSystem* GetSystem () { return system; }
			ComponentId GetId () { return id; }

		};



		/**
		 *	Define Macros
		 */
#define ECS_COMPONENT(T, TComponentSystem)\
		struct T : public ING::ECS::Component {\
		\
		public:\
			friend class TComponentSystem;\
			\
		public:\
			T(ING::ECS::Entity* entity, IComponentSystem* system, ComponentId id) : ING::ECS::Component(entity, system, id) {}

	}

}
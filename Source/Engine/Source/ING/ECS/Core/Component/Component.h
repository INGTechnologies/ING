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



		struct Component
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Component(Entity* entity) :
				entity(entity)
			{}

			~Component() {}



			/**
			 *	Properties
			 */
		protected:
			Entity* entity;

		public:
			Entity* GetEntity () { return entity; }

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
			T(ING::ECS::Entity* entity) : ING::ECS::Component(entity) {}

	}

}
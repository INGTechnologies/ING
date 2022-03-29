#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;


/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



/**
 *	Include ECS Core
 */
#include <ING/ECS/Core/Core.h>



namespace ING {

	namespace ECS {

		class TransformSystem;



		/**
		 *	Component
		 */
		static ING_API struct Transform : 
			public Component,
			public ING::TransformS,
			public ING::TransformM
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Transform(Entity* entity) :
				Component(entity)
			{}



			/**
			 *	Methods
			 */
		public:
			TransformM& GetMatrices() { return (TransformM&)(*this); }

		};



		/**
		 *	Component Pointer
		 */
		using TransformPtr = ComponentPtr<Transform, TransformSystem>;



		/**
		 *	Component System
		 */
		static ING_API ECS_COMPONENT_SYSTEM(TransformSystem, Transform)

		public:
			virtual void Init() override;
			virtual void Release() override;



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake(TransformPtr componentPtr) override;
			virtual void Start(TransformPtr componentPtr) override;
			virtual void Update() override;
			virtual void Destroy(TransformPtr componentPtr) override;

		};

	}

}
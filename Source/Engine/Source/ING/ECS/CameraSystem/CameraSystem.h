#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;


/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include ECS Core
 */
#include <ING/ECS/Core/Core.h>



namespace ING {

	namespace ECS {

		class CameraSystem;



		/**
		 *	Component
		 */
		static ING_API struct Camera : 
			public Component
		{

		public:
			friend class CameraSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Camera(Entity* entity) :
				Component(entity)
			{}



			/**
			 *	Properties
			 */
		private:
			ING::Camera* ingCamera;

		public:
			ING::Camera* GetINGCamera() { return ingCamera; }

		};



		/**
		 *	Component Pointer
		 */
		using CameraPtr = ComponentPtr<ECS::Camera, CameraSystem>;



		/**
		 *	Component System
		 */
		static ING_API ECS_COMPONENT_SYSTEM(CameraSystem, ECS::Camera)

		public:
			virtual void Init() override;
			virtual void Release() override;

							

			/**
			 *	Methods
			 */
		public:
			void CopyDataForRendering(Camera& camera);



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake(CameraPtr componentPtr) override;
			virtual void Start(CameraPtr componentPtr) override;
			virtual void PreUpdate() override;
			virtual void Update() override;
			virtual void Destroy(CameraPtr componentPtr) override;

		};

	}

}
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
		static ING_API struct Camera {

			/**
			 *	Properties
			 */
		private:
			ING::Camera* ingCamera;

		public:
			ING::Camera* GetINGCamera() { return ingCamera; }
		


			/**
			 *	Operators
			 */
		public:
			ING::Camera* operator->() {

				return ingCamera;

			}

		};



		/**
		 *	Component Pointer
		 */
		using CameraPtr = ComponentPtr<Camera, CameraSystem>;



		/**
		 *	Component System
		 */
		static ING_API ECS_COMPONENT_SYSTEM(CameraSystem, Camera)

		public:
			virtual void Init() override;
			virtual void Release() override;



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake(CameraPtr componentPtr) override;
			virtual void Start(CameraPtr componentPtr) override;
			virtual void Update() override;
			virtual void Destroy(CameraPtr componentPtr) override;

		};

	}

}
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
		static ECS_COMPONENT(Camera, CameraSystem)

			/**
			 *	Properties
			 */
		private:
			ING::Camera*			ingCamera;

		public:
			ING::Camera*			GetINGCamera		() { return ingCamera; }

		public:
			bool					IsActive			() { return ingCamera->IsActive(); }

			void					SetActive			(bool isActive) { ingCamera->SetActive(isActive); }

			const RMatrix4x4&		GetViewMatrix		() { return ingCamera->GetViewMatrix(); }
			const RMatrix4x4&		GetProjectionMatrix	() { return ingCamera->GetProjectionMatrix(); }

			const TransformM&		GetTransform		() { return ingCamera->GetTransform(); }

			void					SetTransform		(TransformM transformM) { ingCamera->SetTransform(transformM); }

			float					GetFOV				() { ingCamera->GetFOV(); }
			void					SetFOV				(float fov) { ingCamera->SetFOV(fov); }

			float					GetNearPlane		() { return ingCamera->GetNearPlane(); }
			void					SetNearPlane		(float nearPlane) { ingCamera->SetNearPlane(nearPlane); }
			float					GetFarPlane			() { return ingCamera->GetFarPlane(); }
			void					SetFarPlane			(float farPlane) { ingCamera->SetFarPlane(farPlane); }

			Screen*					GetScreen			() { return ingCamera->GetScreen(); }
			void					SetScreen			(Screen* screen) { return ingCamera->SetScreen(screen); }

			Rendering::Scene*		GetRenderingScene	() { return ingCamera->GetRenderingScene(); }
			void					SetRenderingScene	(Rendering::Scene* renderingScene) { ingCamera->SetRenderingScene(renderingScene); }

			void*					GetRenderingData	() { return ingCamera->GetRenderingScene(); }
			void					SetRenderingData	(void* renderingData) { ingCamera->SetRenderingData(renderingData); }

			Rendering::IPipeline*	GetRenderingPipeline() { return ingCamera->GetRenderingPipeline(); }
			void					SetRenderingPipeline(Rendering::IPipeline* renderingPipeline) { ingCamera->SetRenderingPipeline(renderingPipeline); }

			CAMERA_TARGET_MODE		GetTargetMode		() { return ingCamera->GetTargetMode(); }
			void					SetTargetMode		(CAMERA_TARGET_MODE mode) { ingCamera->SetTargetMode(mode); }

			unsigned int			GetClientWidth		() { return ingCamera->GetClientWidth(); }
			unsigned int			GetClientHeight		() { return ingCamera->GetClientHeight(); }

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
			virtual void LateUpdate() override;
			virtual void Destroy(CameraPtr componentPtr) override;

		};

	}

}
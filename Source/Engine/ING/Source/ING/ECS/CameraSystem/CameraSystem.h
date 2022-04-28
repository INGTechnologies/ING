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
 *	Include Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include Repository
 */
#include <ING/ECS/Repository/Repository.h>



/**
 *	Include Entity
 */
#include <ING/ECS/Entity/Entity.h>



namespace ING {

	namespace ECS {

		class CameraSystem;



		/**
		 *	Component
		 */
		struct Camera :

			public Component

		{

		public:
			friend class CameraSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Camera(Entity* entity, IComponentSystem* system, ComponentId id) :
				Component(entity, system, id)
			{}



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

			const TransformM&		GetTransformM		() { return ingCamera->GetTransformM(); }

			void					SetTransformM		(const ING::TransformM& newTransformM) { ingCamera->SetTransformM(newTransformM); }

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

			Rendering::ICameraData*	GetRenderingData	() { return ingCamera->GetRenderingData(); }
			void					SetRenderingData	(Rendering::ICameraData* renderingData) { ingCamera->SetRenderingData(renderingData); }

			Rendering::IPipeline*	GetRenderingPipeline() { return ingCamera->GetRenderingPipeline(); }
			void					SetRenderingPipeline(Rendering::IPipeline* renderingPipeline) { ingCamera->SetRenderingPipeline(renderingPipeline); }

			CameraTargetMode		GetTargetMode		() { return ingCamera->GetTargetMode(); }
			void					SetTargetMode		(CameraTargetMode mode) { ingCamera->SetTargetMode(mode); }

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
		class ING_API CameraSystem : public ING::ECS::ComponentSystem<Camera, CameraSystem> {
				
		public:
			friend class ING::ECS::Repository; 
				
		protected:
			CameraSystem(ING::ECS::Repository* repository) : ING::ECS::ComponentSystem<Camera, CameraSystem>(repository) {}



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
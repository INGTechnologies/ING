
/**
 *	Include Header
 */
#include "CameraSystem.h"



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include Transform System
 */
#include "../TransformSystem/TransformSystem.h"



namespace ING {

	namespace ECS {

		/**
		 *	Init And Release Methods
		 */
		void CameraSystem::Init() {

			

		}

		void CameraSystem::Release() {

			IComponentSystem::Release();

		}



		/**
		 *	Methods
		 */
		void CameraSystem::CopyDataForRendering(Camera& camera) {

			TransformPtr transform = GetRepository()->GetComponentSystem<TransformSystem>()->GetComponent(camera.GetEntity());

			camera.SetTransformM(transform->GetMatrices());

		}



		/**
		 *	Event Methods
		 */
		void CameraSystem::Awake(CameraPtr componentPtr) {

			componentPtr->ingCamera = new ING::Camera();

		}

		void CameraSystem::Start(CameraPtr componentPtr) {



		}

		void CameraSystem::PreUpdate() {

			for (auto& camera : *this) {

				CopyDataForRendering(camera);

			}

		}

		void CameraSystem::Update() {



		}

		void CameraSystem::LateUpdate() {

			for (auto& camera : *this) {



			}

		}

		void CameraSystem::Destroy(CameraPtr componentPtr) {

			componentPtr->GetINGCamera()->Release();

		}

	}

}
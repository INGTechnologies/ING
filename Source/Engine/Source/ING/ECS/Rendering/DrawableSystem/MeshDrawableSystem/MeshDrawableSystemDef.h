#pragma once

/**
 *	Include Header
 */
#include "MeshDrawableSystem.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Transform Component System
 */
#include <ING/ECS/TransformSystem/TransformSystem.h>



namespace ING {

	namespace ECS {

		/**
		 *	Init And Release Methods
		 */
		void MeshDrawableSystem::Init() {



		}

		void MeshDrawableSystem::Release() {

			IComponentSystem::Release();

		}



		/**
		 *	Methods
		 */
		void MeshDrawableSystem::CopyDataForRendering(MeshDrawable& drawable) {

			TransformPtr transform = GetRepository()->GetComponentSystem<TransformSystem>()->GetComponent(drawable.GetEntity());

			drawable.SetTransform(transform->GetMatrices());

		}



		/**
		 *	Event Methods
		 */
		void MeshDrawableSystem::Awake(MeshDrawablePtr componentPtr) {

			componentPtr->ingMeshDrawable = new ING::Rendering::MeshDrawable();

		}

		void MeshDrawableSystem::Start(MeshDrawablePtr componentPtr) {



		}

		void MeshDrawableSystem::PreUpdate() {

			for(auto& drawable : *this){

				CopyDataForRendering(drawable);
				
			};

		}

		void MeshDrawableSystem::Update() {



		}

		void MeshDrawableSystem::LateUpdate() {

			for (auto& drawable : *this) {



			};

		}

		void MeshDrawableSystem::Destroy(MeshDrawablePtr componentPtr) {

			componentPtr->ingMeshDrawable->Release();

		}

	}

}
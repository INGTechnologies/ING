#pragma once

/**
 *	Include Header
 */
#include "TransformSystem.h"



namespace ING {

	namespace ECS {

		/**
		 *	Init And Release Methods
		 */
		void TransformSystem::Init() {



		}

		void TransformSystem::Release() {

			IComponentSystem::Release();

		}



		/**
		 *	Methods
		 */
		void TransformSystem::Awake(TransformPtr componentPtr) {



		}

		void TransformSystem::Start(TransformPtr componentPtr) {



		}

		void TransformSystem::Update() {



		}

		void TransformSystem::Destroy(TransformPtr componentPtr) {



		}

	}

}
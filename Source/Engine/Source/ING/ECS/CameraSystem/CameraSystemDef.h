#pragma once

/**
 *	Include Header
 */
#include "CameraSystem.h"



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
		void CameraSystem::Awake(CameraPtr componentPtr) {



		}

		void CameraSystem::Start(CameraPtr componentPtr) {



		}

		void CameraSystem::Update() {



		}

		void CameraSystem::Destroy(CameraPtr componentPtr) {



		}

	}

}
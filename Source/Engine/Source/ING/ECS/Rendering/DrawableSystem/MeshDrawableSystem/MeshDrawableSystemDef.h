#pragma once

/**
 *	Include Header
 */
#include "MeshDrawableSystem.h"



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
		void MeshDrawableSystem::Awake(MeshDrawablePtr componentPtr) {



		}

		void MeshDrawableSystem::Start(MeshDrawablePtr componentPtr) {



		}

		void MeshDrawableSystem::Update() {



		}

		void MeshDrawableSystem::Destroy(MeshDrawablePtr componentPtr) {



		}

	}

}
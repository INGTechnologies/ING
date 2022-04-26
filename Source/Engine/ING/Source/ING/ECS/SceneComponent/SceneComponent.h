#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



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



/**
 *	Include Scene Component
 */
#include <ING/Scene/Component/Component.h>



namespace ING {

	namespace ECS {

		class ING_API SceneComponent : public ING::SceneComponent<ECS::SceneComponent> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			SceneComponent();
			~SceneComponent();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release() override;

		};

	}

}
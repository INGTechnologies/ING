
/**
 *	Include Header
 */
#include "ReflectionSystem.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Rendering StandardRP Pipeline
 */
#include <ING/Rendering/StandardRP/Pipeline/Pipeline.h>



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationReflectionSystem::ApplicationReflectionSystem(IApplicationComponent* component) :
			ApplicationComponentOverride(component, "EditorReflectionSystem")
		{



		}

		ApplicationReflectionSystem::~ApplicationReflectionSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationReflectionSystem::Init()
		{



			return ApplicationComponentOverride::Init();

		}

		void ApplicationReflectionSystem::Release()
		{

			ApplicationComponentOverride::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationReflectionSystem::Start() {

			ApplicationComponentOverride::Start();

		}

		void	ApplicationReflectionSystem::PreUpdate() {

			ApplicationComponentOverride::PreUpdate();

		}

		void	ApplicationReflectionSystem::Update() {

			ApplicationComponentOverride::Update();

		}

		void	ApplicationReflectionSystem::LateUpdate() {

			ApplicationComponentOverride::LateUpdate();

		}

		void	ApplicationReflectionSystem::PreRender() {

			ApplicationComponentOverride::PreRender();

		}

		void	ApplicationReflectionSystem::Render() {

			ApplicationComponentOverride::Render();

		}

		void	ApplicationReflectionSystem::LateRender() {

			ApplicationComponentOverride::LateRender();

		}

	}
	
}
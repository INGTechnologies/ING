
/**
 *	Include Header
 */
#include "UISystem.h"



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
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationUISystem::ApplicationUISystem(IApplicationComponent* component) :
			ApplicationComponentOverride(component, "EditorUISystem")
		{



		}

		ApplicationUISystem::~ApplicationUISystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationUISystem::Init()
		{

			return ApplicationComponentOverride::Init();

		}

		void ApplicationUISystem::Release()
		{

			ApplicationComponentOverride::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationUISystem::Start() {

			ApplicationComponentOverride::Start();

		}

		void	ApplicationUISystem::PreUpdate() {

			ApplicationComponentOverride::PreUpdate();

		}

		void	ApplicationUISystem::Update() {

			ApplicationComponentOverride::Update();

		}

		void	ApplicationUISystem::LateUpdate() {

			ApplicationComponentOverride::LateUpdate();

		}

		void	ApplicationUISystem::PreRender() {

			ApplicationComponentOverride::PreRender();

		}

		void	ApplicationUISystem::Render() {

			ApplicationComponentOverride::Render();

		}

		void	ApplicationUISystem::LateRender() {

			ApplicationComponentOverride::LateRender();

		}

	}
	
}
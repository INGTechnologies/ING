
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



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include Editor Tab
 */
#include <ING/Editor/UI/Tab/Tab.h>



/**
 *	Include Editor TabGroup
 */
#include <ING/Editor/UI/TabGroup/TabGroup.h>



/**
 *	Include Editor SceneTab
 */
#include <ING/Editor/UI/Tab/SceneTab/SceneTab.h>



/**
 *	Include Editor SceneExplorerTab
 */
#include <ING/Editor/UI/Tab/SceneExplorerTab/SceneExplorerTab.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationUISystem::ApplicationUISystem(IApplicationComponent* component) :
			ApplicationComponentOverride(component, "EditorUISystem")
		{

			IApplicationModule* module = new IApplicationModule("ING.Editor.UI");

			module->RegisterType<UI::C_Tab>();
			module->RegisterType<UI::C_SceneTab>();
			module->RegisterType<UI::C_SceneExplorerTab>();
			module->RegisterType<UI::C_TabGroup>();

			module->AddDependencies("ING.UI");

			GetApplication()->AddModule(module);

			GetApplication()->GetModule("ING.Editor")->AddDependencies("ING.Editor.UI");

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
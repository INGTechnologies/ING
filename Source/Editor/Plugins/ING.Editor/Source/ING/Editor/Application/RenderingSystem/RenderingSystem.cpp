
/**
 *	Include Header
 */
#include "RenderingSystem.h"



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
 *	Include Rendering StandardRP Application Module
 */
#include <ING/Rendering/StandardRP/Application/Module/Module.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationRenderingSystem::ApplicationRenderingSystem(IApplicationComponent* component) :
			ApplicationComponentOverride(component, "EditorRenderingSystem")
		{

			if (!GetApplication()->IsHasModule("ING.Rendering.StandardRP"))
				new Rendering::StandardRP::ApplicationModule(GetApplication());



			IApplicationModule* module = new IApplicationModule("ING.Editor.Rendering", GetApplication());

			module->AddDependency("ING");
			module->AddDependency("ING.Rendering.StandardRP");



			GetApplication()->GetModule("ING.Editor")->AddDependency("ING.Editor.Rendering");

		}

		ApplicationRenderingSystem::~ApplicationRenderingSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationRenderingSystem::Init()
		{

			//GetComponent()->GetMainPipeline()->Release();

			//GetComponent()->SetMainPipeline(new Rendering::StandardRP::Pipeline("ING.Editor.Rendering.Pipeline"));

			return ApplicationComponentOverride::Init();

		}

		void ApplicationRenderingSystem::Release()
		{

			ApplicationComponentOverride::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationRenderingSystem::Start() {

			ApplicationComponentOverride::Start();

		}

		void	ApplicationRenderingSystem::PreUpdate() {

			ApplicationComponentOverride::PreUpdate();

		}

		void	ApplicationRenderingSystem::Update() {

			ApplicationComponentOverride::Update();

		}

		void	ApplicationRenderingSystem::LateUpdate() {

			ApplicationComponentOverride::LateUpdate();

		}

		void	ApplicationRenderingSystem::PreRender() {

			ApplicationComponentOverride::PreRender();

		}

		void	ApplicationRenderingSystem::Render() {

			ApplicationComponentOverride::Render();

		}

		void	ApplicationRenderingSystem::LateRender() {

			ApplicationComponentOverride::LateRender();

		}

	}
	
}
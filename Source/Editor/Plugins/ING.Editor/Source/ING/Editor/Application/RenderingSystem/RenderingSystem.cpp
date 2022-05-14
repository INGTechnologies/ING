
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
 *	Include Rendering StandardRP Pipeline
 */
#include <ING/Rendering/StandardRP/Pipeline/Pipeline.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationRenderingSystem::ApplicationRenderingSystem(IApplication* application) :
			IApplicationComponent(application, "EditorRenderingSystem"),

			mainPipeline(0)
		{



		}

		ApplicationRenderingSystem::~ApplicationRenderingSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationRenderingSystem::Init()
		{

			mainPipeline = new Rendering::StandardRP::Pipeline("ING.Editor.Rendering.Pipeline");

			return IApplicationComponent::Init();

		}

		void ApplicationRenderingSystem::Release()
		{

			if (mainPipeline != 0) {

				mainPipeline->Release();

			}

			IApplicationComponent::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationRenderingSystem::Start() {

			IApplicationComponent::Start();

		}

		void	ApplicationRenderingSystem::PreUpdate() {

			IApplicationComponent::PreUpdate();

		}

		void	ApplicationRenderingSystem::Update() {

			IApplicationComponent::Update();

		}

		void	ApplicationRenderingSystem::LateUpdate() {

			IApplicationComponent::LateUpdate();

		}

		void	ApplicationRenderingSystem::PreRender() {

			IApplicationComponent::PreRender();

		}

		void	ApplicationRenderingSystem::Render() {

			IApplicationComponent::Render();

		}

		void	ApplicationRenderingSystem::LateRender() {

			IApplicationComponent::LateRender();

		}

	}
	
}
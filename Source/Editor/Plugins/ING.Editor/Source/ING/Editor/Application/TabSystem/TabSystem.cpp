
/**
 *	Include Header
 */
#include "TabSystem.h"



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
 *	Include Layout
 */
#include <ING/Editor/Layout/Layout.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Editor Tab
 */
#include <ING/Editor/UI/Tab/Tab.h>



/**
 *	Include Editor Tab Creator
 */
#include <ING/Editor/UI/Tab/Creator/Creator.h>



/**
 *	Include Editor Scene Tab
 */
#include <ING/Editor/UI/Tab/SceneTab/SceneTab.h>



/**
 *	Include Editor Hierarchy Tab
 */
#include <ING/Editor/UI/Tab/SceneExplorerTab/SceneExplorerTab.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationTabSystem::ApplicationTabSystem(IApplication* application) :
			IApplicationComponent(application, "EditorTabSystem")
		{



		}

		ApplicationTabSystem::~ApplicationTabSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationTabSystem::Init()
		{

			AddTabCreator(new UI::TabCreator<UI::SceneTab>("View.Scene"));
			AddTabCreator(new UI::TabCreator<UI::SceneExplorerTab>("View.SceneExplorer"));

			return IApplicationComponent::Init();

		}

		void ApplicationTabSystem::Release()
		{

			for (auto item = name2TabCreatorMap.begin(); item != name2TabCreatorMap.end();) {

				(item++)->second->Release();

			}

			IApplicationComponent::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationTabSystem::AddTabCreator(UI::ITabCreator* tabCreator) {

			name2TabCreatorMap[tabCreator->GetName()] = tabCreator;

		}

		void	ApplicationTabSystem::RemoveTabCreator(UI::ITabCreator* tabCreator) {

			name2TabCreatorMap.erase(tabCreator->GetName());

		}

		void	ApplicationTabSystem::Start() {

			IApplicationComponent::Start();

		}

		void	ApplicationTabSystem::PreUpdate() {

			IApplicationComponent::PreUpdate();

		}

		void	ApplicationTabSystem::Update() {

			IApplicationComponent::Update();

		}

		void	ApplicationTabSystem::LateUpdate() {

			IApplicationComponent::LateUpdate();

		}

		void	ApplicationTabSystem::PreRender() {

			IApplicationComponent::PreRender();

		}

		void	ApplicationTabSystem::Render() {

			IApplicationComponent::Render();

		}

		void	ApplicationTabSystem::LateRender() {

			IApplicationComponent::LateRender();

		}

	}
	
}
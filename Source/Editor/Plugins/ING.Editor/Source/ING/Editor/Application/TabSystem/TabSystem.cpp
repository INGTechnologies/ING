
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
 *	Include Editor Scene Tab
 */
#include <ING/Editor/UI/Tab/SceneTab/SceneTab.h>



/**
 *	Include Editor Hierarchy Tab
 */
#include <ING/Editor/UI/Tab/HierarchyTab/HierarchyTab.h>



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



			return IApplicationComponent::Init();

		}

		void ApplicationTabSystem::Release()
		{

			for (auto item = name2TabMap.begin(); item != name2TabMap.end();) {

				(item++)->second->Release();

			}

			IApplicationComponent::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationTabSystem::AddTab(UI::ITab* tab) {

			name2TabMap[tab->GetName()] = tab;

		}

		void	ApplicationTabSystem::RemoveTab(UI::ITab* tab) {

			name2TabMap.erase(tab->GetName());

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
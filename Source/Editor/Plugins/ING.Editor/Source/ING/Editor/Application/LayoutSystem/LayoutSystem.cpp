
/**
 *	Include Header
 */
#include "LayoutSystem.h"



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
 *	Include Editor Layout
 */
#include <ING/Editor/Layout/Layout.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationLayoutSystem::ApplicationLayoutSystem(IApplication* application) :
			IApplicationComponent(application, "EditorLayoutSystem")
		{



		}

		ApplicationLayoutSystem::~ApplicationLayoutSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationLayoutSystem::Init()
		{

			Layout* defaultLayout = new Layout(
				"ING.Editor.DefaultLayout",

				{

					{

						{

							{



							},

							LAYOUT_DIRECTION_NONE,

							{
					
								"View.Scene"
				
							}

						},

						{

							{



							},

							LAYOUT_DIRECTION_NONE,

							{

								"View.Hierarchy"

							}

						}

					},

					LAYOUT_DIRECTION_ROW

				}

			);

			AddLayout(defaultLayout);

			return IApplicationComponent::Init();

		}

		void ApplicationLayoutSystem::Release()
		{

			for (auto item = name2LayoutMap.begin(); item != name2LayoutMap.end();) {

				(item++)->second->Release();

			}

			IApplicationComponent::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationLayoutSystem::AddLayout(Layout* layout) {

			name2LayoutMap[layout->GetName()] = layout;

		}

		void	ApplicationLayoutSystem::RemoveLayout(Layout* layout) {

			name2LayoutMap.erase(layout->GetName());

		}

		void	ApplicationLayoutSystem::Start() {

			IApplicationComponent::Start();

		}

		void	ApplicationLayoutSystem::PreUpdate() {

			IApplicationComponent::PreUpdate();

		}

		void	ApplicationLayoutSystem::Update() {

			IApplicationComponent::Update();

		}

		void	ApplicationLayoutSystem::LateUpdate() {

			IApplicationComponent::LateUpdate();

		}

		void	ApplicationLayoutSystem::PreRender() {

			IApplicationComponent::PreRender();

		}

		void	ApplicationLayoutSystem::Render() {

			IApplicationComponent::Render();

		}

		void	ApplicationLayoutSystem::LateRender() {

			IApplicationComponent::LateRender();

		}

	}
	
}
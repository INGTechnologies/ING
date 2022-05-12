
/**
 *	Include Header
 */
#include "SceneExplorerTab.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include Style
 */
#include <ING/UI/Style/Style.h>



namespace ING {

	namespace Editor {

		namespace UI {

			/**
			 *	Constructors And Destructor
			 */
			SceneExplorerTab::SceneExplorerTab() :
				ITab("View.SceneExplorer"),

				sceneTab(0)
			{



			}

			SceneExplorerTab::~SceneExplorerTab()
			{



			}



			/**
			 *	Release Methods
			 */
			void SceneExplorerTab::Release() {

				ITab::Release();
			}



			/**
			 *	Methods
			 */
			void	SceneExplorerTab::Start() {

				ITab::Start();

			}

			void	SceneExplorerTab::PreUpdate() {

				ITab::PreUpdate();

			}

			void	SceneExplorerTab::Update() {

				ITab::Update();

			}

			void	SceneExplorerTab::LateUpdate() {

				ITab::LateUpdate();

			}

			void	SceneExplorerTab::PreRender() {

				ITab::PreRender();

			}

			void	SceneExplorerTab::Render() {

				ITab::Render();

			}

			void	SceneExplorerTab::LateRender() {

				ITab::LateRender();

			}

			void	SceneExplorerTab::Resize() {

				ITab::Resize();

			}

		}

	}

}
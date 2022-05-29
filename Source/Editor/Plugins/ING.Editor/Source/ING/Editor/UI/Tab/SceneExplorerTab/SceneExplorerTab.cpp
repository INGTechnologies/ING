
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

			ING_BEGIN_REFLECTED_CLASS
				(SceneExplorerTab, ITab)

				ING_CLASS_CONSTRUCTOR
					(SceneExplorerTab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void SceneExplorerTab::Constructor(const String& name) {

				ITab::Constructor(name);

				sceneTab = 0;

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
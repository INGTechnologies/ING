
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
				(C_SceneExplorerTab, C_Tab)

				ING_CLASS_CONSTRUCTOR
					(C_SceneExplorerTab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void C_SceneExplorerTab::Constructor(const String& name) {

				C_Tab::Constructor(name);

				sceneTab = 0;

			}



			/**
			 *	Release Methods
			 */
			void C_SceneExplorerTab::Release() {

				C_Tab::Release();
			}



			/**
			 *	Methods
			 */
			void	C_SceneExplorerTab::Start() {

				C_Tab::Start();

			}

			void	C_SceneExplorerTab::PreUpdate() {

				C_Tab::PreUpdate();

			}

			void	C_SceneExplorerTab::Update() {

				C_Tab::Update();

			}

			void	C_SceneExplorerTab::LateUpdate() {

				C_Tab::LateUpdate();

			}

			void	C_SceneExplorerTab::PreRender() {

				C_Tab::PreRender();

			}

			void	C_SceneExplorerTab::Render() {

				C_Tab::Render();

			}

			void	C_SceneExplorerTab::LateRender() {

				C_Tab::LateRender();

			}

			void	C_SceneExplorerTab::Resize() {

				C_Tab::Resize();

			}

		}

	}

}
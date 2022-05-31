
/**
 *	Include Header
 */
#include "SceneTab.h"



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
				(C_SceneTab, C_Tab)

				ING_CLASS_CONSTRUCTOR
					(C_SceneTab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void C_SceneTab::Constructor(const String& name) {

				C_Tab::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void C_SceneTab::Release() {

				C_Tab::Release();
			}



			/**
			 *	Methods
			 */
			void	C_SceneTab::Start() {

				C_Tab::Start();

			}

			void	C_SceneTab::PreUpdate() {

				C_Tab::PreUpdate();

			}

			void	C_SceneTab::Update() {

				C_Tab::Update();

			}

			void	C_SceneTab::LateUpdate() {

				C_Tab::LateUpdate();

			}

			void	C_SceneTab::PreRender() {

				C_Tab::PreRender();

			}

			void	C_SceneTab::Render() {

				C_Tab::Render();

			}

			void	C_SceneTab::LateRender() {

				C_Tab::LateRender();

			}

			void	C_SceneTab::Resize() {

				C_Tab::Resize();

			}

		}

	}

}
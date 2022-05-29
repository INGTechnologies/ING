
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
				(SceneTab, ITab)

				ING_CLASS_CONSTRUCTOR
					(SceneTab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void SceneTab::Constructor(const String& name) {

				ITab::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void SceneTab::Release() {

				ITab::Release();
			}



			/**
			 *	Methods
			 */
			void	SceneTab::Start() {

				ITab::Start();

			}

			void	SceneTab::PreUpdate() {

				ITab::PreUpdate();

			}

			void	SceneTab::Update() {

				ITab::Update();

			}

			void	SceneTab::LateUpdate() {

				ITab::LateUpdate();

			}

			void	SceneTab::PreRender() {

				ITab::PreRender();

			}

			void	SceneTab::Render() {

				ITab::Render();

			}

			void	SceneTab::LateRender() {

				ITab::LateRender();

			}

			void	SceneTab::Resize() {

				ITab::Resize();

			}

		}

	}

}
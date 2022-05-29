
/**
 *	Include Header
 */
#include "Tab.h"



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
				(ITab, IElement)

				ING_CLASS_CONSTRUCTOR
					(ITab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void ITab::Constructor(const String& name) {

				IElement::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void ITab::Release() {

				IElement::Release();
			}



			/**
			 *	Methods
			 */
			void	ITab::Start() {

				IElement::Start();

			}

			void	ITab::PreUpdate() {

				IElement::PreUpdate();

			}

			void	ITab::Update() {

				IElement::Update();

			}

			void	ITab::LateUpdate() {

				IElement::LateUpdate();

			}

			void	ITab::PreRender() {

				IElement::PreRender();

			}

			void	ITab::Render() {

				IElement::Render();

			}

			void	ITab::LateRender() {

				IElement::LateRender();

			}

			void	ITab::Resize() {

				IElement::Resize();

			}

		}

	}

}
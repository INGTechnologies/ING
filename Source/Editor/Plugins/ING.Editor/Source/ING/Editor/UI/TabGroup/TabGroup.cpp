
/**
 *	Include Header
 */
#include "TabGroup.h"



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
				(TabGroup, IElement)

				ING_CLASS_CONSTRUCTOR
					(TabGroup, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void TabGroup::Constructor(const String& name) {

				IElement::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void TabGroup::Release() {

				IElement::Release();
			}



			/**
			 *	Methods
			 */
			void	TabGroup::Start() {

				IElement::Start();

			}

			void	TabGroup::PreUpdate() {

				IElement::PreUpdate();

			}

			void	TabGroup::Update() {

				IElement::Update();

			}

			void	TabGroup::LateUpdate() {

				IElement::LateUpdate();

			}

			void	TabGroup::PreRender() {

				IElement::PreRender();

			}

			void	TabGroup::Render() {

				IElement::Render();

			}

			void	TabGroup::LateRender() {

				IElement::LateRender();

			}

			void	TabGroup::Resize() {

				IElement::Resize();

			}

		}

	}

}
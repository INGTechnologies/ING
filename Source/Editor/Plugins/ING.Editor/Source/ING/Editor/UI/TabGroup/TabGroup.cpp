
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
				(C_TabGroup, C_Element)

				ING_CLASS_CONSTRUCTOR
					(C_TabGroup, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void C_TabGroup::Constructor(const String& name) {

				C_Element::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void C_TabGroup::Release() {

				C_Element::Release();
			}



			/**
			 *	Methods
			 */
			void	C_TabGroup::Start() {

				C_Element::Start();

			}

			void	C_TabGroup::PreUpdate() {

				C_Element::PreUpdate();

			}

			void	C_TabGroup::Update() {

				C_Element::Update();

			}

			void	C_TabGroup::LateUpdate() {

				C_Element::LateUpdate();

			}

			void	C_TabGroup::PreRender() {

				C_Element::PreRender();

			}

			void	C_TabGroup::Render() {

				C_Element::Render();

			}

			void	C_TabGroup::LateRender() {

				C_Element::LateRender();

			}

			void	C_TabGroup::Resize() {

				C_Element::Resize();

			}

		}

	}

}
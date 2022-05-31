
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
				(C_Tab, ING::UI::C_Element)

				ING_CLASS_CONSTRUCTOR
					(C_Tab, const String&)
					.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
					.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

			ING_END_REFLECTED_CLASS
				()



			/**
			 *	Constructor
			 */
			void C_Tab::Constructor(const String& name) {

				C_Element::Constructor(name);

			}



			/**
			 *	Release Methods
			 */
			void C_Tab::Release() {

				C_Element::Release();
			}



			/**
			 *	Methods
			 */
			void	C_Tab::Start() {

				C_Element::Start();

			}

			void	C_Tab::PreUpdate() {

				C_Element::PreUpdate();

			}

			void	C_Tab::Update() {

				C_Element::Update();

			}

			void	C_Tab::LateUpdate() {

				C_Element::LateUpdate();

			}

			void	C_Tab::PreRender() {

				C_Element::PreRender();

			}

			void	C_Tab::Render() {

				C_Element::Render();

			}

			void	C_Tab::LateRender() {

				C_Element::LateRender();

			}

			void	C_Tab::Resize() {

				C_Element::Resize();

			}

		}

	}

}
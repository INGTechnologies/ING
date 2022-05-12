
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

			/**
			 *	Constructors And Destructor
			 */
			ITab::ITab(const String& name) :
				IElement(name)
			{



			}

			ITab::~ITab()
			{



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
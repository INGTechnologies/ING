
/**
 * Include Header
 */
#include "UI.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>




namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			UIDrawable::UIDrawable() {



			}

			UIDrawable::~UIDrawable() {



			}



			/**
			 *	Release Methods
			 */
			void UIDrawable::Release() {

				delete this;

			}



			/**
			 *	Methods
			 */
			void UIDrawable::Draw() {



			}

		}

	}

}
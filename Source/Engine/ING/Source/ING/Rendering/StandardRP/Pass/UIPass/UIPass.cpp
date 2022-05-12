
/**
 * Include Header
 */
#include "UIPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			UIPass::UIPass(const String& name) : IPass(name) {



			}

			UIPass::~UIPass() {



			}



			/**
			 *	Release Methods
			 */
			void UIPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool UIPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
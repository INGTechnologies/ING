
/**
 * Include Header
 */
#include "TransparentPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			TransparentPass::TransparentPass(const String& name) : IPass(name) {



			}

			TransparentPass::~TransparentPass() {



			}



			/**
			 *	Release Methods
			 */
			void TransparentPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool TransparentPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}

/**
 * Include Header
 */
#include "PostProcessPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			PostProcessPass::PostProcessPass(const String& name) : IPass(name) {



			}

			PostProcessPass::~PostProcessPass() {



			}



			/**
			 *	Release Methods
			 */
			void PostProcessPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool PostProcessPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}

/**
 * Include Header
 */
#include "Final.h"



namespace ING {

	namespace Rendering {

		namespace SubRP {

			/**
			 *	Constructors And Destructor
			 */
			FinalPass::FinalPass(std::string name) : Pass(name) {



			}

			FinalPass::~FinalPass() {



			}



			/**
			 *	Release Methods
			 */
			void FinalPass::Release() {

				Pass::Release();

			}



			/**
			 *	Methods
			 */
			void FinalPass::CustomRender(IDeviceContext* context, Camera* camera, PassInput* input, PassOutput* output) {



			}

		}

	}

}
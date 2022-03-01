
/**
 * Include Header
 */
#include "Final.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			FinalPass::FinalPass(std::string name) : Pass<FinalPassInput, FinalPassOutput>(name) {



			}

			FinalPass::~FinalPass() {



			}



			/**
			 *	Release Methods
			 */
			void FinalPass::Release() {

				Pass<FinalPassInput, FinalPassOutput>::Release();

			}



			/**
			 *	Methods
			 */
			void FinalPass::CustomRender(IDeviceContext* context, Camera* camera, FinalPassInput* input, FinalPassOutput* output) {



			}

		}

	}

}

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
			FinalPass::FinalPass(String name) : Pass<FinalPassInput, FinalPassOutput>(name) {



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
			bool FinalPass::CustomRender(IDeviceContext* context, Camera* camera, const FinalPassInput& input, FinalPassOutput& output) {



				return true;
			}

		}

	}

}

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
			bool FinalPass::CustomRender(IDeviceContext* context, Camera* camera, const PassInput& input, PassOutput& output) {



				return true;
			}

		}

	}

}
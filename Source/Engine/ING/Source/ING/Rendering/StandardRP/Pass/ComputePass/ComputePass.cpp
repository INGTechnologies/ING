
/**
 * Include Header
 */
#include "ComputePass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			ComputePass::ComputePass(const String& name) : IPass(name) {



			}

			ComputePass::~ComputePass() {



			}



			/**
			 *	Release Methods
			 */
			void ComputePass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool ComputePass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
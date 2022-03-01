
/**
 * Include Header
 */
#include "Main.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			MainPass::MainPass(std::string name) : Pass<MainPassInput, MainPassOutput>(name) {



			}

			MainPass::~MainPass() {



			}



			/**
			 *	Release Methods
			 */
			void MainPass::Release() {

				Pass<MainPassInput, MainPassOutput>::Release();

			}



			/**
			 *	Methods
			 */
			void MainPass::CustomRender(DeviceContext* context, Camera* camera, MainPassInput* input, MainPassOutput* output) {



			}

		}

	}

}
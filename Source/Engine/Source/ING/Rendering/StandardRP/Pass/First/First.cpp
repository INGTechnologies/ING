
/**
 * Include Header
 */
#include "First.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			FirstPass::FirstPass(std::string name) : Pass<FirstPassInput, FirstPassOutput>(name) {



			}

			FirstPass::~FirstPass() {



			}



			/**
			 *	Release Methods
			 */
			void FirstPass::Release() {

				Pass<FirstPassInput, FirstPassOutput>::Release();

			}



			/**
			 *	Methods
			 */
			void FirstPass::CustomRender(IDeviceContext* context, Camera* camera, FirstPassInput* input, FirstPassOutput* output) {



			}

		}

	}

}
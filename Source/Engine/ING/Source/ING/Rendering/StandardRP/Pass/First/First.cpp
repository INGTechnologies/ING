
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
			bool FirstPass::CustomRender(IDeviceContext* context, Camera* camera, const FirstPassInput& input, FirstPassOutput& output) {



				return true;
			}

		}

	}

}
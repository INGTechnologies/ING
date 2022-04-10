
/**
 * Include Header
 */
#include "First.h"



namespace ING {

	namespace Rendering {

		namespace SubRP {

			/**
			 *	Constructors And Destructor
			 */
			FirstPass::FirstPass	(std::string name) : Pass(name) {



			}

			FirstPass::~FirstPass	() {



			}



			/**
			 *	Release Methods
			 */
			void FirstPass::Release() {

				Pass::Release();

			}



			/**
			 *	Methods
			 */
			bool FirstPass::CustomRender(IDeviceContext* context, Camera* camera, const PassInput& input, PassOutput& output) {



				return true;
			}

		}

	}

}
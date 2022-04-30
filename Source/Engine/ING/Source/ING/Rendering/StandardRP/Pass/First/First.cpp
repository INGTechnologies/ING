
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
			FirstPass::FirstPass(const String& name) : IPass(name) {



			}

			FirstPass::~FirstPass() {



			}



			/**
			 *	Release Methods
			 */
			void FirstPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool FirstPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}

/**
 * Include Header
 */
#include "OpaquePass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			OpaquePass::OpaquePass(const String& name) : IPass(name) {



			}

			OpaquePass::~OpaquePass() {



			}



			/**
			 *	Release Methods
			 */
			void OpaquePass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool OpaquePass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
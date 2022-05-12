
/**
 * Include Header
 */
#include "GBufferPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			GBufferPass::GBufferPass(const String& name) : IPass(name) {



			}

			GBufferPass::~GBufferPass() {



			}



			/**
			 *	Release Methods
			 */
			void GBufferPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool GBufferPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
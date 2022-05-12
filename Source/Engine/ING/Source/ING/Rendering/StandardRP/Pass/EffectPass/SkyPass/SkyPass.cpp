
/**
 * Include Header
 */
#include "SkyPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			SkyPass::SkyPass(const String& name) : IPass(name) {



			}

			SkyPass::~SkyPass() {



			}



			/**
			 *	Release Methods
			 */
			void SkyPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool SkyPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}

/**
 * Include Header
 */
#include "DepthPrepass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			DepthPrepass::DepthPrepass(const String& name) : IPass(name) {



			}

			DepthPrepass::~DepthPrepass() {



			}



			/**
			 *	Release Methods
			 */
			void DepthPrepass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool DepthPrepass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
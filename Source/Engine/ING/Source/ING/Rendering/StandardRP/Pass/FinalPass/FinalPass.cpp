
/**
 * Include Header
 */
#include "FinalPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			FinalPass::FinalPass(const String& name) : IPass(name) {



			}

			FinalPass::~FinalPass() {



			}



			/**
			 *	Release Methods
			 */
			void FinalPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool FinalPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}

/**
 * Include Header
 */
#include "EffectPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			EffectPass::EffectPass(const String& name) : IPass(name) {



			}

			EffectPass::~EffectPass() {



			}



			/**
			 *	Release Methods
			 */
			void EffectPass::Release() {

				IPass::Release();

			}



			/**
			 *	Methods
			 */
			bool EffectPass::Render(IDeviceContext* context, Camera* camera) {



				return true;
			}

		}

	}

}
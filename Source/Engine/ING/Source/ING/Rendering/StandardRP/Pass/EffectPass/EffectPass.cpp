
/**
 * Include Header
 */
#include "EffectPass.h"



 /**
  * Include Child Passes
  */
#include "OpaquePass/OpaquePass.h"
#include "SkyPass/SkyPass.h"
#include "TransparentPass/TransparentPass.h"



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			EffectPass::EffectPass(const String& name) :
				IPass(name),

				skyPass(0),
				opaquePass(0),
				transparentPass(0)
			{

				skyPass			= new SkyPass(name + ToString(".SkyPass"));
				opaquePass		= new OpaquePass(name + ToString(".OpaquePass"));
				transparentPass = new TransparentPass(name + ToString(".TransparentPass"));

				AddChild(skyPass);
				AddChild(opaquePass);
				AddChild(transparentPass);

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
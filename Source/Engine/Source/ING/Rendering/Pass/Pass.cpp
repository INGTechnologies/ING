
/**
 * Include Header
 */
#include "Pass.h"



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IPass::IPass	(std::string name) {

			this->name = name;

		}

		IPass::~IPass	() {



		}



		/**
		 *	Release Methods
		 */
		void IPass::Release	() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IPass::Render(IDeviceContext* context, Camera* camera, void* input, void* output) {



		}

	}

}
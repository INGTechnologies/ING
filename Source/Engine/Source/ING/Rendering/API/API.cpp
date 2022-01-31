
/**
 *	Include Header
 */
#include "API.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		API::API() {

			convertor = Convertor::Create();

		}

		API::~API() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool API::Init() {

			device = Device::Create();

			return true;
		}

		bool API::Release() {

			if (device != nullptr) {

				device->Release();

			}

			return true;
		}

	}
}


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
		IAPI::IAPI() {

			convertor = IConvertor::Create();

		}

		IAPI::~IAPI() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool IAPI::Init() {

			device = IDevice::Create();

			return true;
		}

		bool IAPI::Release() {

			if (device != nullptr) {

				device->Release();

			}

			return true;
		}

	}
}

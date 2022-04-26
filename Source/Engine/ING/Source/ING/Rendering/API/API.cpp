
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



/**
 *	Include Format
 */
#include <ING/Rendering/API/Format/Format.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IAPI::IAPI() : 
			device(0) 
		{

			convertor = IConvertor::Create();

		}

		IAPI::~IAPI() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool IAPI::Init() {

			/* Create Device */
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


/**
 *	Include Header
 */
#include "API.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			API::API() {



			}

			API::~API() {



			}



			/**
			 *	Init, Run, Release Methods
			 */
			bool API::Init() {

				

				return Rendering::IAPI::Init();
			}

			bool API::Release() {



				return Rendering::IAPI::Release();
			}

		}

	}
}

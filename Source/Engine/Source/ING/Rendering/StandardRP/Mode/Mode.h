#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			enum Mode {

				MODE_FORWARD,
				MODE_DEFERRED

			};

		}

	}

}
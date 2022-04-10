#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Rendering {

		enum Usage {
			USAGE_DEFAULT,
			USAGE_IMMUTABLE,
			USAGE_DYNAMIC,
			USAGE_STAGING
		};

	}

}
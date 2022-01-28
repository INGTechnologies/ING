#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Rendering {

		enum PrimitiveTopology {

			POINT_LIST,

			LINE_LIST,

			LINE_LIST_WADJ,

			LINE_STRIP,

			LINE_STRIP_WADJ,

			TRIANGLE_LIST,

			TRIANGLE_LIST_WADJ,

			TRIANGLE_STRIP,

			TRIANGLE_STRIP_WADJ

		};

	}

}
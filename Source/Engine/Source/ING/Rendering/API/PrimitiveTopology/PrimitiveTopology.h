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

			LINE_LIST_ADJ,

			LINE_STRIP,

			LINE_STRIP_ADJ,

			TRIANGLE_LIST,

			TRIANGLE_LIST_ADJ,

			TRIANGLE_STRIP,

			TRIANGLE_STRIP_ADJ

		};

	}

}
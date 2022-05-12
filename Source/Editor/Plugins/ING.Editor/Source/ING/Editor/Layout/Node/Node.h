#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



namespace ING {

	namespace Editor {

		enum LayoutDirection {

			LAYOUT_DIRECTION_NONE,
			LAYOUT_DIRECTION_ROW,
			LAYOUT_DIRECTION_COLUMN,
			LAYOUT_DIRECTION_ROW_INV,
			LAYOUT_DIRECTION_COLUMN_INV

		};



		struct PLUGIN_API(ING_EDITOR) LayoutNode
		{

			std::vector<LayoutNode> childVector;

			LayoutDirection			direction = LAYOUT_DIRECTION_COLUMN;

			std::vector<String>		tabVector;

		};

	}

}
#pragma once

#include "../EntryPoint/EntryPoint.h"
#include <ING/Utils/Utils.h>



/**
 *	Declare Classes
 */
namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Info
 */
DECLARE_PLUGIN(ING_OPENWORLD);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_OPENWORLD, bool, PreRelease)	();
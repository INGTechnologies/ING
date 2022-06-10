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
DECLARE_PLUGIN(DEMO_PLUGIN_3);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreRelease)	();
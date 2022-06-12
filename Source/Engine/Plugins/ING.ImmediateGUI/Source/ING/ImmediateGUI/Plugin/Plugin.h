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
DECLARE_PLUGIN(ING_IMMEDIATEGUI);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreRelease)	();
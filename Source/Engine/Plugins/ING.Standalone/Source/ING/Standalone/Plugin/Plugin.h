#pragma once

#include <ING/Standalone/EntryPoint/EntryPoint.h>
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
DECLARE_PLUGIN(ING_STANDALONE);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreRelease)	();
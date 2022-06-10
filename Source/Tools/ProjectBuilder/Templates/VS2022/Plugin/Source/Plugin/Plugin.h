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
DECLARE_PLUGIN($(INGPluginVarName));



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, Unload)		();

DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreRelease)	();
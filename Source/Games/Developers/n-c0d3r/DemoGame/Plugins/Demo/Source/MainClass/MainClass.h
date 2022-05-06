#pragma once

#include <EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Events
 */
PLUGIN_EVENT bool PluginLoad		(ING::Engine* engine, ING::IPlugin * plugin);
PLUGIN_EVENT bool PluginUnload		();

PLUGIN_EVENT void PluginLateCreate	();

PLUGIN_EVENT void PluginPreInit		();
PLUGIN_EVENT void PluginLateInit	();

PLUGIN_EVENT void PluginPreRun		();
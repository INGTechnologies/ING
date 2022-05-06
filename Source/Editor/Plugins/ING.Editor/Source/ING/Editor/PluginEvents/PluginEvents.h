#pragma once

#include <ING/Editor/EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Events
 */
#ifdef ING_EDITOR_EXPORTS
ING_EDITOR_EVENT bool PluginLoad		(ING::Engine* engine, ING::IPlugin * plugin);
ING_EDITOR_EVENT bool PluginUnload		();

ING_EDITOR_EVENT void PluginLateCreate	();

ING_EDITOR_EVENT void PluginPreInit		();
ING_EDITOR_EVENT void PluginLateInit	();

ING_EDITOR_EVENT void PluginPreRun		();
#endif
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
extern "C" DEMO_API bool PluginLoad		(ING::Engine* engine, ING::IPlugin * plugin);
extern "C" DEMO_API bool PluginUnload	();

extern "C" DEMO_API void PluginLateCreate();

extern "C" DEMO_API void PluginPreInit();
extern "C" DEMO_API void PluginLateInit();

extern "C" DEMO_API void PluginPreRun();
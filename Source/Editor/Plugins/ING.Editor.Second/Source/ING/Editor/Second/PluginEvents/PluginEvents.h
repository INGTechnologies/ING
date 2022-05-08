#pragma once

#include <ING/Editor/Second/EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



namespace ING {

	class Engine;
	class IPlugin;

}



DECLARE_PLUGIN_NAME(ING_EDITOR_SECOND);

DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, bool, Unload)		();

DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, LateCreate)	();

DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, PreInit)		();
DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, LateInit)		();

DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, PreRun)		();

DECLARE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, PreRelease)	();
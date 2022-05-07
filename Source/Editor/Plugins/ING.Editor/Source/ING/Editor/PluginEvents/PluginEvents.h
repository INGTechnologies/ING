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
ING_EDITOR_EVENT bool INGEditor_PluginLoad		(ING::Engine* engine, ING::IPlugin * plugin);
ING_EDITOR_EVENT bool INGEditor_PluginUnload	();

ING_EDITOR_EVENT void INGEditor_PluginLateCreate();

ING_EDITOR_EVENT void INGEditor_PluginPreInit	();
ING_EDITOR_EVENT void INGEditor_PluginLateInit	();

ING_EDITOR_EVENT void INGEditor_PluginPreRun	();

ING_EDITOR_EVENT void INGEditor_PluginPreRelease();
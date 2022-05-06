
#include "PluginEvents.h"

#include <iostream>

#include <ING/Engine/Engine.h>

#include <ING/_Debug/Debug.h>

#include <ING/Plugin/Plugin.h>

#include <ING/Plugin/Manager/Manager.h>

#ifdef ING_EDITOR_EXPORTS
bool PluginLoad(ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(engine, plugin);

	return true;
}

bool PluginUnload() {



	return true;
}

void PluginLateCreate() {



}

void PluginPreInit() {



}
void PluginLateInit() {



}

void PluginPreRun() {



}
#endif
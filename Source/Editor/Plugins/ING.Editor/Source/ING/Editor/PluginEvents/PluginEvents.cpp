
#include "PluginEvents.h"

#include <iostream>

#include <ING/Engine/Engine.h>

#include <ING/_Debug/Debug.h>

#include <ING/Plugin/Plugin.h>

#include <ING/Plugin/Manager/Manager.h>

bool INGEditor_PluginLoad(ING::Engine* engine, ING::IPlugin* plugin) {

	int a = 5;

	DEFAULT_PLUGIN_LOAD(engine, plugin);

	return false;
}

bool INGEditor_PluginUnload() {



	return true;
}

void INGEditor_PluginLateCreate() {



}

void INGEditor_PluginPreInit() {



}
void INGEditor_PluginLateInit() {



}

void INGEditor_PluginPreRun() {



}

void INGEditor_PluginPreRelease() {



}
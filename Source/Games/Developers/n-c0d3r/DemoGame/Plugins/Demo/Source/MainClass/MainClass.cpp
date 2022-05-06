#include "MainClass.h"

#include <iostream>

#include <ING/Engine/Engine.h>

#include <ING/_Debug/Debug.h>

#include <ING/Plugin/Plugin.h>

#include <ING/Plugin/Manager/Manager.h>

#include <ING/Window/Manager/Manager.h>

#include <ING/Application/Application.h>
#include <ING/Application/Manager/Manager.h>

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
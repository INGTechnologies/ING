
#include "PluginEvents.h"
#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>



#include <ING/Editor/PluginEvents/PluginEvents.h>



DEFINE_PLUGIN_NAME(ING_EDITOR_SECOND);

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(engine, plugin);



	return false;
}

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, bool, Unload) () {



	return true;
}

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, LateCreate) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, PreInit) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, LateInit) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR_SECOND, void, PreRelease) () {



}
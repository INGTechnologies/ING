
#include "PluginEvents.h"
#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>



DEFINE_PLUGIN_NAME(ING_EDITOR);

DEFINE_PLUGIN_EVENT(ING_EDITOR, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(engine, plugin);

	return false;
}

DEFINE_PLUGIN_EVENT(ING_EDITOR, bool, Unload) () {



	return true;
}

DEFINE_PLUGIN_EVENT(ING_EDITOR, void, LateCreate) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR, void, PreInit) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR, void, LateInit) () {



}

DEFINE_PLUGIN_EVENT(ING_EDITOR, void, PreRelease) () {



}
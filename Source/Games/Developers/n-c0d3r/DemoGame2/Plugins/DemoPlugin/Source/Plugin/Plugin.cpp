
#include "Plugin.h"

#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>
#include <ING/Window/Manager/Manager.h>
#include <ING/Application/Application.h>
#include <ING/Application/Manager/Manager.h>



using namespace ING;



/**
 *	Plugin Info
 */
DEFINE_PLUGIN(DEMO_PLUGIN);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(DEMO_PLUGIN, engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, LateInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreRelease) () {

	return true;
}
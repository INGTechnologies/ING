
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
DEFINE_PLUGIN(DEMO_PLUGIN_3);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(DEMO_PLUGIN_3, engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, LateInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_3, bool, PreRelease) () {

	return true;
}

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
DEFINE_PLUGIN(DEMO_PLUGIN_2);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(DEMO_PLUGIN_2, engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, PreInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, LateInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(DEMO_PLUGIN_2, bool, PreRelease) () {

	return true;
}
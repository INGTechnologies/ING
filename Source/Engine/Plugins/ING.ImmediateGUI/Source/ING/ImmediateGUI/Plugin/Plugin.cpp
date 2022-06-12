
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
DEFINE_PLUGIN(ING_IMMEDIATEGUI);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(ING_IMMEDIATEGUI, engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, LateInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_IMMEDIATEGUI, bool, PreRelease) () {

	return true;
}
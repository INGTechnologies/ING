
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
DEFINE_PLUGIN($(INGPluginVarName));



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD($(INGPluginVarName), engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, LateInit) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION($(INGPluginVarName), bool, PreRelease) () {

	return true;
}
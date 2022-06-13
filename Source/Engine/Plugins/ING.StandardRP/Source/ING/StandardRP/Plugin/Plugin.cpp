
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
DEFINE_PLUGIN(ING_STANDARDRP);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(ING_STANDARDRP, engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, Unload) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, LateCreate) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreInit) () {

	/* Continue if engine is in ING.Standalone mode */
	if (Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, LateInit) () {

	/* Continue if engine is in ING.Standalone mode */
	if (Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreRun) () {

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreRelease) () {

	return true;
}
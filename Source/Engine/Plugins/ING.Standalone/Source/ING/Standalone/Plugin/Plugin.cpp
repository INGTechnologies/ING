
#include "Plugin.h"

#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>
#include <ING/Window/Manager/Manager.h>
#include <ING/Application/Application.h>
#include <ING/Application/Manager/Manager.h>



#include <ING/Standalone/GameApplication/GameApplication.h>



/**
 *	Plugin Info
 */
DEFINE_PLUGIN(ING_STANDALONE);



/**
 *	Plugin Events
 */
DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(ING_STANDALONE, engine, plugin);

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, Unload) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, LateCreate) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreInit) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	/* Create Game Application */
	ING::IGameApplication* gameApplication = new ING::Standalone::GameApplication(L"Game:/Config.ini");

	ING::ApplicationManager::GetInstance()->SetGameApplication(gameApplication);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, LateInit) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	if (!ING::ApplicationManager::GetInstance()->GetGameApplication()->Init()) return false;

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreRun) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_STANDALONE, bool, PreRelease) () {

	/* Continue if engine is in ING.Standalone mode */
	if (ING::Engine::GetInstance()->GetMode() != "ING.Standalone") {

		return true;
	}

	return true;
}
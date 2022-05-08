
#include "Plugin.h"

#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>
#include <ING/Window/Manager/Manager.h>
#include <ING/Editor/Application/Application.h>



using namespace ING;



DEFINE_PLUGIN_NAME(ING_EDITOR);

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(engine, plugin);

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, Unload) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateCreate) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreInit) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	/* To run the editor, we need 2 arguments (the first one is program directory path and the second is project directory path) */
	if (Engine::GetInstance()->GetArgv().size() < 2) {

		return false;

	}

	/* Create Editor Application */
	WString projectPath = Engine::GetInstance()->GetArgv()[1];
	Editor::Application* editorApplication = new Editor::Application(L"Game:/Config.ini", projectPath);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateInit) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	if(!Editor::Application::GetInstance()->Init()) return false;

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRun) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRelease) () {

	/* Continue if engine is in ING.Editor mode */
	if (Engine::GetInstance()->GetMode() != "ING.Editor") {

		return true;
	}

	Editor::Application::GetInstance()->Release();

	return true;
}
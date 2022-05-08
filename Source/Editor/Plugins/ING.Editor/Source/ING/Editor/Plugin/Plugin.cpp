
#include "Plugin.h"

#include <iostream>
#include <ING/Engine/Engine.h>
#include <ING/_Debug/Debug.h>
#include <ING/Plugin/Plugin.h>
#include <ING/Plugin/Manager/Manager.h>
#include <ING/Window/Manager/Manager.h>

/**
 *	Include Editor Application
 */
#include <ING/Editor/Application/Application.h>

using namespace ING;



DEFINE_PLUGIN_NAME(ING_EDITOR);

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, Load) (ING::Engine* engine, ING::IPlugin* plugin) {

	DEFAULT_PLUGIN_LOAD(engine, plugin);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, Unload) () {



	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateCreate) () {



	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreInit) () {

	/* To run the editor, we need 2 arguments (the first one is program directory path and the second is project directory path) */
	if (Engine::GetInstance()->GetArgv().size() < 2) {

		return false;

	}

	WString projectPath = Engine::GetInstance()->GetArgv()[1];

	Editor::Application* editorApplication = new Editor::Application(L"Game:/Config.ini", projectPath);

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateInit) () {

	if(!Editor::Application::GetInstance()->Init()) return false;

	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRun) () {



	return true;
}

DEFINE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRelease) () {

	Editor::Application::GetInstance()->Release();

	return true;
}
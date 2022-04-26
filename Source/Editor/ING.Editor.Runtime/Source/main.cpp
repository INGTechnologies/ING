
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Editor Application
 */
#include "ING/Editor/Application/Application.h"



/**
 *	Include GameApplication
 */
#include <ING/Editor/Game/Application/Application.h>



int main(int argc, char** argv) {

	ING::Engine::CreateInstance();

	if (!ING::Engine::GetInstance()->Init()) return 1;

	std::string projectPath = std::string(argv[1]);

	ING::Editor::Application* editorApplication = new ING::Editor::Application("Game:/Config.ini", projectPath);

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
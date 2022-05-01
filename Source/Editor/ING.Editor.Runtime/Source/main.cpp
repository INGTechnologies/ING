
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



int main(int argc, char** argv)
{

	WString projectPath = ToWString((const char*)argv[1]);

	ING::Engine::CreateInstance();

	ING::Editor::Application* editorApplication = new ING::Editor::Application(L"Game:/Config.ini", projectPath);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	if (!editorApplication->Init()) return 1;

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
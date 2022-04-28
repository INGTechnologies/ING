
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



/*
#ifdef USE_MSVC

#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

	std::string projectPath = "";// std::string(argv[1]);

	ING::Engine::CreateInstance();

	ING::Engine::GetInstance()->SetProgramHandle(hInstance);

	ING::Editor::Application* editorApplication = new ING::Editor::Application("Game:/Config.ini", projectPath);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	if (!editorApplication->Init()) return 1;

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}

#endif
*/

int main(int argc, char** argv)
{

	std::string projectPath = std::string(argv[1]);

	ING::Engine::CreateInstance();

	ING::Editor::Application* editorApplication = new ING::Editor::Application("Game:/Config.ini", projectPath);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	if (!editorApplication->Init()) return 1;

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
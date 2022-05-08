
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Style
 */
#include <ING/UI/Style/Style.h>



/**
 *	Include Element
 */
#include <ING/UI/Element/Element.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include UISystem
 */
#include <ING/Application/UISystem/UISystem.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#ifdef USE_MSVC
int wmain(int argc, wchar_t* argv_cstr[], wchar_t* envp[])
{

	std::vector<WString> argv(argc);

	for (unsigned int i = 0; i < argc; ++i) {

		argv[i] = ToWString(argv_cstr[i]);

	}

	WString projectPath = argv[1];

	ING::Engine::CreateInstance(argv);

	ING::IPlugin* plugin = ING::IPlugin::Create(L"Game:/Plugins/ING.Editor.Second/ING.Editor.Second.dll");

	plugin->Load();

	//ING::Editor::Application* editorApplication = new ING::Editor::Application(L"Game:/Config.ini", projectPath);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	//if (!editorApplication->Init()) return 1;

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
#endif
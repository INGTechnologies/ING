
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include ApplicationWindowManager
 */
#include <ING/Application/Window/Manager/Manager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



int main() {

	ING::Engine::CreateInstance();

	ING::Engine::GetInstance()->Init();

	ING::IApplication* application = new ING::IApplication("Game:\\MainApplication.ini");

	application->GetWindowManager()->AddWindow(
	
		new ING::Window({

			800,

			600,

			L"MainApplication",

			"MainWindow",

			true

		})
	
	);

	ING::Engine::GetInstance()->Run();

	return 0;
}
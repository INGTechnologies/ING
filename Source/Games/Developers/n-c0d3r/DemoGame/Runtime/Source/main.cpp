
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
#include <ING/Application/WindowManager/WindowManager.h>



/**
 *	Include ApplicationRenderingSystem
 */
#include <ING/Application/RenderingSystem/RenderingSystem.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



static ING::IApplication* application = 0;

using namespace ING::Rendering;
using namespace ING;



int main() {

	ING::Engine::CreateInstance();

	application = new ING::IApplication(L"Game:\\ApplicationConfig.ini");

	ING::Engine::GetInstance()->Init();

	if(!application->Init())return 1;

	application->GetWindowManager()->AddWindow(
	
		ING::IWindow::Create({

			800,

			600,

			L"MainApplication",

			"MainWindow",

			true

		})
	
	);

	ING::Engine::GetInstance()->GetEvent("RUN")->AddListener([](ING::Event* e) {
		
		IPipeline* pipeline = application->GetRenderingSystem()->GetPipeline();

		IPass* pass1 = new IPass("DemoPass1");

		IPass* pass2 = new IPass("DemoPass2");

		pass1->AddChild(pass2);

		pipeline->AddPass(pass1);
			
	});

	ING::Engine::GetInstance()->Run();

	return 0;
}
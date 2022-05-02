
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



using namespace ING::Rendering;
using namespace ING;
using namespace ING::UI;



static IApplication* application = 0;
static IWindow* mainWindow = 0;



int main() {

	ING::Engine::CreateInstance();

	application = new ING::IApplication(L"Game:\\ApplicationConfig.ini");

	ING::Engine::GetInstance()->Init();

	if(!application->Init())return 1;

	mainWindow = ING::IWindow::Create({

			800,

			600,

			L"MainApplication",

			"MainWindow",

			true

	});

	application->GetWindowManager()->AddWindow(
	
		mainWindow
	
	);

	ING::Engine::GetInstance()->GetEvent("RUN")->AddListener([](ING::Event* e) {
		
		IElement* rootElement = application->GetUISystem()->GetRootElement();

		IElement* demoElement = new IElement();

		rootElement->GetNode()->AddChild(demoElement->GetNode());

		float size = 5.0f;
		
		demoElement->GetStyle()->SetSize(
		
			UI_DVECTOR2(
				UI_GET(0), UI_GET(1),
				size, size
			)
		
		);

		mainWindow->SetStyle(ING_WS_POPUP);

	});

	ING::Engine::GetInstance()->Run();

	return 0;
}
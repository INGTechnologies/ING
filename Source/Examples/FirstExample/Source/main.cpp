
/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Thread And Thread Manager
 */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



/**
 *	Include Event And Event Manager
 */
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h> 



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h> 



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h> 



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h> 



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h> 



/**
 *	Include Window
 */
#include <ING/Window/Window.h> 



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h> 



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h> 



/**
 *	Include DX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h> 



/**
 *	Include Time
 */
#include <ING/Time/Time.h> 



/**
 *	Include Math
 */
#include <ING/Math/Math.h> 

using namespace ING::Math;



/**
 *	Include Color
 */
#include <ING/Color/Color.h> 



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h> 



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h> 



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h> 



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h> 



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h> 



using namespace ING;



static struct ExampleC {

	ECS::ComponentId id = 0;

};



static ECS_COMPONENT_SYSTEM(ExampleCSystem, ExampleC)

public:
	virtual void Init		() override;
	virtual void Release	() override;



	/**
	 *	Event Methods
	 */
public:
	virtual void Awake(ECS::ComponentPtr<ExampleC, ExampleCSystem> componentPtr) override;
	virtual void Start(ECS::ComponentPtr<ExampleC, ExampleCSystem> componentPtr) override;
	virtual void Update() override;

};

		

void ExampleCSystem::Init() {

	

}

void ExampleCSystem::Release() {

	ComponentSystem<ExampleC, ExampleCSystem>::Release();

}



void ExampleCSystem::Awake(ECS::ComponentPtr<ExampleC, ExampleCSystem> componentPtr) {

	Debug::Log(String("ExampleC ") + String(componentPtr.GetId()) + String(" Awake"));

}

void ExampleCSystem::Start(ECS::ComponentPtr<ExampleC, ExampleCSystem> componentPtr) {

	//Debug::Log(String("ExampleC ") + String(componentPtr.GetId()) + String(" Start"));

}

void ExampleCSystem::Update() {

	ECS::ComponentSystem<ExampleC, ExampleCSystem>::Update();



	/**
	 *	Show FPS In Window Title
	 */
	static float t = 0;
	 
	t += Time::GetDeltaTime();

	if (t >= 1.0f) {

		t = 0;

		WindowManager::GetInstance()->GetMainWindow()->SetTitle(WString(L"FPS: ") + WString(Time::GetFPS()));

	}

	for (ExampleC& component : *this) {

		component.id = component.id * component.id * component.id;

	}

}



int main() {

	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();



	Window* consoleWindow = WindowManager::GetInstance()->GetConsoleWindow();

	consoleWindow->Show();



	ING::Application::GetInstance()->GetEvent("RUN")->AddListener([](Event* event) {

		ECS::Repository* repository = new ECS::Repository();

		repository->SetActive(true);



		ExampleCSystem* exampleCSystem = repository->CreateComponentSystem<ExampleCSystem>();



		Camera* camera = new Camera();

		camera->SetActive(true);



		camera->SetScreen(ScreenManager::GetInstance()->GetMainScreen());



		camera->SetFOV(Math::Deg2Rad * 90.0f);

		camera->SetFarPlane(1000.0f);

		camera->SetNearPlane(0.1f);



		Rendering::Scene* renderingScene = new Rendering::Scene("Example Rendering Scene");

		camera->SetRenderingScene(renderingScene);




		for (unsigned long i = 0; i < 0; ++i) {

			ECS::Entity* entity = repository->CreateEntity();

			exampleCSystem->AddComponent(entity)->id = i;

		}

	});



	ING::Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->Run();

	return 0;
}
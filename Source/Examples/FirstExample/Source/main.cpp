
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



using namespace ING;



static struct ExampleC {

	ECS::ComponentId id;

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

	//Debug::Log(String("ExampleC ") + String(componentPtr.GetId()) + String(" Awake"));

}

void ExampleCSystem::Start(ECS::ComponentPtr<ExampleC, ExampleCSystem> componentPtr) {

	//Debug::Log(String("ExampleC ") + String(componentPtr.GetId()) + String(" Start"));

}

void ExampleCSystem::Update() {

	ECS::ComponentSystem<ExampleC, ExampleCSystem>::Update();

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



		for (unsigned long i = 0; i < 199990; ++i) {

			ECS::Entity* entity = repository->CreateEntity();

			exampleCSystem->AddComponent(entity);

		}

		
		exampleCSystem->Foreach([](ExampleC& component, ECS::ComponentPtr<ExampleC, ExampleCSystem>& ptr) {

			component.id = ptr.GetId();

		});

		//exampleCSystem->Foreach([](ExampleC& component, ECS::ComponentPtr<ExampleC, ExampleCSystem>& ptr) {

		//	Debug::Log(String(ptr.GetComponentSystem()->GetArray().Id2Index(component.id)));

		//});

		/* Check If Id Repeated */
		for (unsigned long i = 0; i < exampleCSystem->GetArray().GetFilledCount() - 1; ++i) {

			if (i != exampleCSystem->GetArray().Id2Index(exampleCSystem->GetArray().Index2Id(i))) {

				Debug::Log(false);

			}

		}
		



		ExampleCSystem* exampleCSystem2 = repository->CreateComponentSystem<ExampleCSystem>();

	});



	ING::Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->Run();

	return 0;
}
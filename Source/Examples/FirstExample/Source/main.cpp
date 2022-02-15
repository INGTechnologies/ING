
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
 *	Include ECS Repository Manager
 */
#include <ING/ECS/Repository/Manager/Manager.h> 



/**
 *	Include ECS Repository
 */
#include <ING/ECS/Repository/Repository.h> 



/**
 *	Include ECS Entity
 */
#include <ING/ECS/Entity/Entity.h> 



/**
 *	Include ECS Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include ECS Component Ptr
 */
#include <ING/ECS/Component/Ptr/Ptr.h>



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include ECS Component Array
 */
#include <ING/ECS/Component/Array/Array.h>



using namespace ING;



static struct Transform {

	Vector3 pos;

};



static ECS_COMPONENT_SYSTEM_CLASS(Transform, TransformSystem){

public:
	ECS_COMPONENT_SYSTEM_CONSTRUCTOR(Transform, TransformSystem) {



	}

	ECS_COMPONENT_SYSTEM_DESTRUCTOR(Transform, TransformSystem) {



	}

};



int main() {
	 


	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();



	Window* consoleWindow = WindowManager::GetInstance()->GetConsoleWindow();

	consoleWindow->Show();



	ING::Application::GetInstance()->GetEvent("RUN")->AddListener([](Event* event) {

		ECS::Repository* repository = new ECS::Repository();



		TransformSystem* transformSystem = repository->CreateComponentSystem<TransformSystem>();



		ECS::ComponentArray<Transform>& cArray = transformSystem->GetArray();



		ECS::Entity* entity = new ECS::Entity();



		ECS::ComponentPtr<Transform, TransformSystem> transformPtr = transformSystem->AddComponent(entity);

		transformSystem->Foreach([](Transform& transform) {
			
			transform.pos = Vector3(1,2,3);
			
		});



		Debug::Log((*transformPtr).pos);



		repository->ReleaseComponentSystem<TransformSystem>();

	});



	ING::Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {



	});


	ING::Application::GetInstance()->Run();

	return 0;
}
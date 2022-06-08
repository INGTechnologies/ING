
/**
 *	Include Header
 */
#include "ActorSystem.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Actor
 */
#include <ING/Actor/Actor.h>



/**
 *	Include ActorComponent
 */
#include <ING/Actor/Component/Component.h>



/**
 *	Include Reflection System
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationActorSystem::ApplicationActorSystem(IApplication* application) :
		IApplicationComponent(application, "ActorSystem")
	{

		IApplicationModule* module = new IApplicationModule("ING.Actor");

		module->RegisterType<C_Actor>();
		module->RegisterType<C_ActorComponent>();

		GetApplication()->AddModule(module);

		GetApplication()->GetModule("ING")->AddDependency("ING.Actor");

	}

	ApplicationActorSystem::~ApplicationActorSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationActorSystem::Init() {



		return IApplicationComponent::Init();
	}

	void ApplicationActorSystem::Release() {



		IApplicationComponent::Release();

	}



	/**
	 *	Methods
	 */
	void	ApplicationActorSystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationActorSystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationActorSystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationActorSystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationActorSystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationActorSystem::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationActorSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}

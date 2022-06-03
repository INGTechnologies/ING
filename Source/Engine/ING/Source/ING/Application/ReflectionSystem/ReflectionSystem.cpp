
/**
 *	Include Header
 */
#include "ReflectionSystem.h"



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
 *	Include Reflection Context
 */
#include <ING/Reflection/Context/Context.h>



/**
 *	Include Actor
 */
#include <ING/Actor/Actor.h>



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
	ApplicationReflectionSystem::ApplicationReflectionSystem(IApplication* application) :
		IApplicationComponent(application, "ReflectionSystem"),

		context(0),
		isTypesRegistered(false)
	{



	}

	ApplicationReflectionSystem::~ApplicationReflectionSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationReflectionSystem::Init() {

		context = new Reflection::Context();



		for (auto item : GetApplication()->GetSortedModuleVector()) {

			item->RegisterTypes();

		}

		for (auto item : typeCreatorList) {

			item(context);

		}

		isTypesRegistered = true;



		return IApplicationComponent::Init();
	}

	void ApplicationReflectionSystem::Release() {



		for (auto item : GetApplication()->GetSortedModuleVector()) {

			item->UnregisterTypes();

		}

		for (auto item : typeDestructorList) {

			item(context);

		}



		if (context != 0) {

			context->Release();

		}



		IApplicationComponent::Release();

	}



	/**
	 *	Properties
	 */
	void	ApplicationReflectionSystem::SetContext(Reflection::Context* context) {

		this->context = context;

	}
		
	void	ApplicationReflectionSystem::ReleaseContext() {

		if (context != 0) {

			context->Release();

			context = 0;

		}

	}



	/**
	 *	Methods
	 */
	void	ApplicationReflectionSystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationReflectionSystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationReflectionSystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationReflectionSystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationReflectionSystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationReflectionSystem::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationReflectionSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}

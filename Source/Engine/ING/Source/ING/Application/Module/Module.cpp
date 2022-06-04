
/**
 *	Include Header
 */
#include "Module.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	/**
	 *	Constructor And Destructors
	 */
	IApplicationModule::IApplicationModule(const String& name) :
		name(name),
		application(0)
	{

		canRegisterTypes = true;
		canUnregisterTypes = false;

	}

	IApplicationModule::~IApplicationModule() {



	}



	/**
	 *	Release Methods
	 */
	void IApplicationModule::Release() {

		if (application != 0) {

			if (application->IsHasComponent("ReflectionSystem")) {

				UnregisterTypes();

			}

			application->RemoveModule(this);

		}

		typeRegisterList.Clear();

		delete this;

	}



	/**
	 *	Methods
	 */
	ApplicationReflectionSystem* IApplicationModule::GetReflectionSystem() {

		return application->GetReflectionSystem();

	}

	void IApplicationModule::AddDependencies(const String& dependencyName) {

		dependenciesMap[dependencyName] = true;

	}

	void IApplicationModule::RemoveDependencies(const String& dependencyName) {

		dependenciesMap.erase(dependencyName);

	}

	void IApplicationModule::RegisterTypes() {

		canRegisterTypes = false;
		canUnregisterTypes = true;

		for (auto item : typeRegisterList) {

			item(this, application->GetReflectionSystem());

		}

	}

	void IApplicationModule::UnregisterTypes() {

		for (auto item : typeUnregisterList) {

			item(this, application->GetReflectionSystem());

		}

		canRegisterTypes = true;
		canUnregisterTypes = false;

	}

}
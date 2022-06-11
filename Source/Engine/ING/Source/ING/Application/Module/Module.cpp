
/**
 *	Include Header
 */
#include "Module.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



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
		application(0),
		isLoaded(false)
	{

		if (!ApplicationManager::GetInstance()->IsHasModule(name)) {

			ApplicationManager::GetInstance()->name2ModuleInstanceCount[name] = 0;

		}

		ApplicationManager::GetInstance()->name2ModuleInstanceCount[name]++;

	}

	IApplicationModule::~IApplicationModule() {



	}



	/**
	 *	Release Methods
	 */
	void IApplicationModule::Release() {

		if (isLoaded) {

			Unload();

		}

		ApplicationManager::GetInstance()->name2ModuleInstanceCount[name]--;

		if (ApplicationManager::GetInstance()->GetModuleInstanceCount(name) == 0) {

			ApplicationManager::GetInstance()->name2ModuleInstanceCount.erase(name);

		}

		if (application != 0) {

			application->RemoveModule(this);

		}

		delete this;

	}



	/**
	 *	Methods
	 */
	ApplicationReflectionSystem* IApplicationModule::GetReflectionSystem() {

		return application->GetReflectionSystem();

	}

	void IApplicationModule::AddDependency(const String& dependencyName) {

		dependenciesMap[dependencyName] = true;

	}

	void IApplicationModule::RemoveDependency(const String& dependencyName) {

		dependenciesMap.erase(dependencyName);

	}

	void IApplicationModule::Load() {

		if(isLoaded) return;

		for (auto loader : typeLoaderList) {

			loader.Load();

		}

		isLoaded = true;

	}

	void IApplicationModule::Unload() {

		if (!isLoaded) return;

		for (auto unloader : typeUnloaderList) {

			if (
				unloader.reflectionContext == 0
				&& ApplicationManager::GetInstance()->GetModuleInstanceCount(name) > 0
			) {



			}
			else {

				unloader.Unload();

			}

		}

		isLoaded = false;

	}

	void IApplicationModule::Reload() {

		if (!isLoaded) {

			Load();

		}
		else {

			Unload();
			Load();

		}

	}

}
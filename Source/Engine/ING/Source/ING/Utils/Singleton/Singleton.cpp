
/**
 *	Include Header
 */
#include "Singleton.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Plugin Manager
 */
#include <ING/Plugin/Manager/Manager.h>



#include <mutex>



using namespace ING;
using namespace ING::Utils;



std::mutex mutex;

void LoadSingletonInstance(void** wherePtrAre, const ING::Utils::String& name) {

	mutex.lock();

	PluginManager* pluginManager = PluginManager::GetInstance();

	*wherePtrAre = pluginManager->GetPointer(name);

	mutex.unlock();

}



void SetupSingletonInstance(void* instance, const ING::Utils::String& name) {

	if (name == ING::Utils::ToString(typeid(ING::Engine).name())) {



	}
	else if (name == ING::Utils::ToString(typeid(ING::PluginManager).name())) {



	}
	else {

		PluginManager* pluginManager = PluginManager::GetInstance();

		pluginManager->SetPointer(name, instance);

	}

}

ING::Utils::String GetEngineClassName() {

	return ING::Utils::ToString(typeid(ING::Engine).name());

}

ING::Utils::String GetPluginManagerClassName() {

	return ING::Utils::ToString(typeid(ING::PluginManager).name());

}
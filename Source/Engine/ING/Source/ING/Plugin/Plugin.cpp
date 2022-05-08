
/**
 *	Include Header
 */
#include "Plugin.h"



/**
 *	Include MSVC Plugin
 */
#include <ING/Plugin/MSVC/Plugin/Plugin.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Plugin Manager
 */
#include <ING/Plugin/Manager/Manager.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IPlugin::IPlugin(const WString& path) :
		name(""),
		path(path)
	{

		isLoaded = false;

	}

	IPlugin::~IPlugin() {



	}



	/**
	 *	Release Method
	 */
	bool IPlugin::Release() {

		bool result = true;

		if (isLoaded) {

			PreRelease();

			if (!unloadFunction) {

				result = unloadFunction();

			}

			isLoaded = false;

		}

		delete this;

		return result;
	}



	/**
	 *	Methods
	 */
	IPlugin* IPlugin::Create(const WString& path) {

#ifdef USE_MSVC
		return new MSVC::Plugin(path);
#endif

		return 0;
	}

	bool IPlugin::Load() {

		if (!loadFunction) return false;

		PluginManager::GetInstance()->AddPlugin(this);

		isLoaded = true; 
		
		if (!loadFunction(ING::Engine::GetInstance(), this)) return false;

		return true;
	}

	bool IPlugin::Unload() {

		if (!unloadFunction) return true;

		if (!unloadFunction()) return false;

		isLoaded = false;

		PluginManager::GetInstance()->RemovePlugin(this);

		return true;
	}

	bool IPlugin::LateCreate() {

		if (!lateCreateFunction) return false;

		if (!lateCreateFunction()) return false;
	}

	bool IPlugin::PreInit() {

		if (!preInitFunction) return false;

		if (!preInitFunction()) return false;
	}

	bool IPlugin::LateInit() {

		if (!lateInitFunction) return false;

		if (!lateInitFunction()) return false;
	}

	bool IPlugin::PreRun() {

		if (!preRunFunction) return false;

		if (!preRunFunction()) return false;
	}

	bool IPlugin::PreRelease() {

		if (!preReleaseFunction) return false;

		if (!preReleaseFunction()) return false;
	}

}
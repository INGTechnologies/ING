
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
	void IPlugin::Release() {

		PreRelease();

		delete this;
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

		isLoaded = true; 
		
		if (!loadFunction(ING::Engine::GetInstance(), this)) return false;

		return true;
	}

	bool IPlugin::Unload() {

		if (!unloadFunction) return true;

		if (!unloadFunction()) return false;

		isLoaded = false;

		return true;
	}

	void IPlugin::LateCreate() {

		if (!lateCreateFunction) return;

		lateCreateFunction();
	}

	void IPlugin::PreInit() {

		if (!preInitFunction) return;

		preInitFunction();
	}
	void IPlugin::LateInit() {

		if (!lateInitFunction) return;

		lateInitFunction();
	}

	void IPlugin::PreRun() {

		if (!preRunFunction) return;

		preRunFunction();
	}

	void IPlugin::PreRelease() {

		if (!preReleaseFunction) return;

		preReleaseFunction();
	}

}
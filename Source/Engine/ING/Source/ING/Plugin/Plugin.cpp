
/**
 *	Include Header
 */
#include "Plugin.h"



/**
 *	Include MSVC Plugin
 */
#include <ING/Plugin/MSVC/Plugin/Plugin.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IPlugin::IPlugin(const String& name, const WString& path) :
		name(name),
		path(path)
	{



	}

	IPlugin::~IPlugin() {



	}



	/**
	 *	Release Method
	 */
	void IPlugin::Release() {

		delete this;
	}



	/**
	 *	Methods
	 */
	IPlugin* IPlugin::Create(const String& name, const WString& path) {

#ifdef USE_MSVC
		return new MSVC::Plugin(name, path);
#endif

		return 0;
	}

	bool IPlugin::Load() {



		return true;
	}

	bool IPlugin::Unload() {



		return true;
	}

	void IPlugin::LateCreate() {}

	void IPlugin::PreInit	() {}
	void IPlugin::LateInit	() {}

	void IPlugin::PreRun	() {}

}
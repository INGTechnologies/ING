
#ifdef USE_MSVC

/**
 *	Include Header
 */
#include "Plugin.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace MSVC {

		/**
		 *	Constructors And Destructor
		 */
		Plugin::Plugin(const String& name, const WString& path) :
			IPlugin(name, path),

			moduleHandle(0)
		{



		}

		Plugin::~Plugin() {



		}



		/**
		 *	Release Method
		 */
		void Plugin::Release() {

			IPlugin::Release();
		}



		/**
		 *	Methods
		 */
		bool Plugin::Load() {

			if (moduleHandle != 0) return false;

			moduleHandle = LoadLibrary(Path::GetAbsolutePath(GetPath()).c_str());

			if (moduleHandle == 0) {

				Debug::Error(ToWString("Cant Load Plugin ") + GetPath());

				Release();

				return false;

			}

			loadFunction	= (PluginLoadFunction)GetProcAddress(moduleHandle, "PluginLoad");
			unloadFunction	= (PluginUnloadFunction)GetProcAddress(moduleHandle, "PluginUnload");

			lateCreateFunction = (PluginLateCreateFunction)GetProcAddress(moduleHandle, "PluginLateCreate");
			preInitFunction = (PluginPreInitFunction)GetProcAddress(moduleHandle, "PluginPreInit");
			lateInitFunction = (PluginLateInitFunction)GetProcAddress(moduleHandle, "PluginLateInit");
			preRunFunction = (PluginPreRunFunction)GetProcAddress(moduleHandle, "PluginPreRun");

			if (!loadFunction(ING::Engine::GetInstance(), this)) return false;

			return IPlugin::Load();
		}

		bool Plugin::Unload() {

			if (!unloadFunction) return true;

			if (moduleHandle == 0) return false;

			if (!unloadFunction()) return false;

			return IPlugin::Unload();
		}

		void Plugin::LateCreate() {

			if (!lateCreateFunction) return;
		
			lateCreateFunction();

			IPlugin::LateCreate();
		}

		void Plugin::PreInit() {

			if (!preInitFunction) return;

			preInitFunction();

			IPlugin::PreInit();
		}
		void Plugin::LateInit() {

			if (!lateInitFunction) return;

			lateInitFunction();

			IPlugin::LateInit();
		}

		void Plugin::PreRun() {

			if (!preRunFunction) return;

			preRunFunction();

			IPlugin::PreRun();
		}

	}

}

#endif
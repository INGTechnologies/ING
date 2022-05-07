
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

			Debug::Log(Path::GetAbsolutePath(GetPath()));

			moduleHandle = LoadLibrary(Path::GetAbsolutePath(GetPath()).c_str());

			if (moduleHandle == 0) {

				Debug::Error(ToWString("Cant Load Plugin ") + GetPath());

				Release();

				return false;

			}

			loadFunction	= (PluginLoadFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginLoad")).c_str());
			unloadFunction	= (PluginUnloadFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginUnload")).c_str());

			lateCreateFunction = (PluginLateCreateFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginLateCreate")).c_str());
			preInitFunction = (PluginPreInitFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginPreInit")).c_str());
			lateInitFunction = (PluginLateInitFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginLateInit")).c_str());
			preRunFunction = (PluginPreRunFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginPreRun")).c_str());
			preReleaseFunction = (PluginPreReleaseFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PluginPreRelease")).c_str());

			return IPlugin::Load();
		}

		bool Plugin::Unload() {

			if (moduleHandle == 0) return false;

			return IPlugin::Unload();
		}

		void Plugin::LateCreate() {

			if (!lateCreateFunction) return;

			IPlugin::LateCreate();
		}

		void Plugin::PreInit() {

			if (!preInitFunction) return;

			IPlugin::PreInit();
		}
		void Plugin::LateInit() {

			if (!lateInitFunction) return;

			IPlugin::LateInit();
		}

		void Plugin::PreRun() {

			if (!preRunFunction) return;

			IPlugin::PreRun();
		}

		void Plugin::PreRelease() {

			if (!preReleaseFunction) return;

			IPlugin::PreRelease();
		}

	}

}

#endif
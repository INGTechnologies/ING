
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
		Plugin::Plugin(const WString& path) :
			IPlugin(path),

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



		std::string GetLastErrorAsString()
		{
			//Get the error message ID, if any.
			DWORD errorMessageID = ::GetLastError();
			if (errorMessageID == 0) {
				return std::string(); //No error message has been recorded
			}

			LPSTR messageBuffer = nullptr;

			//Ask Win32 to give us the string version of that message ID.
			//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
			size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

			//Copy the error message into a std::string.
			std::string message(messageBuffer, size);

			//Free the Win32's string's buffer.
			LocalFree(messageBuffer);

			return message;
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
				Debug::Error(GetLastErrorAsString());

				Release();

				return false;

			}

			name = ((PluginNameFunction)GetProcAddress(moduleHandle, "PluginName"))();

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
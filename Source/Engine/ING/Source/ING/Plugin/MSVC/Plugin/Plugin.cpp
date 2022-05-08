
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
		bool Plugin::Release() {

			return IPlugin::Release();

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

			moduleHandle = LoadLibrary(Path::GetAbsolutePath(GetPath()).c_str());

			if (moduleHandle == 0) {

				Debug::Error(ToWString("Cant Load Plugin ") + GetPath());
				Debug::Error(GetLastErrorAsString());

				Release();

				return false;

			}

			PluginNameFunction nameFunction = (PluginNameFunction)GetProcAddress(moduleHandle, "PluginName");

			if (!nameFunction) {

				Debug::Error(ToWString("Not Found Plugin Name") + GetPath());

				Release();

				return false;

			}

			name = nameFunction();

			loadFunction	= (PluginLoadFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_Load")).c_str());
			unloadFunction	= (PluginUnloadFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_Unload")).c_str());

			lateCreateFunction = (PluginLateCreateFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_LateCreate")).c_str());
			preInitFunction = (PluginPreInitFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PreInit")).c_str());
			lateInitFunction = (PluginLateInitFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_LateInit")).c_str());
			preRunFunction = (PluginPreRunFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PreRun")).c_str());
			preReleaseFunction = (PluginPreReleaseFunction)GetProcAddress(moduleHandle, (GetName() + ToString("_PreRelease")).c_str());

			return IPlugin::Load();
		}

		bool Plugin::Unload() {

			if (moduleHandle == 0) return false;

			FreeLibrary(moduleHandle);

			return IPlugin::Unload();
		}

		bool Plugin::LateCreate() {

			if (!lateCreateFunction) return false;

			return IPlugin::LateCreate();
		}

		bool Plugin::PreInit() {

			if (!preInitFunction) return false;

			return IPlugin::PreInit();
		}
		bool Plugin::LateInit() {

			if (!lateInitFunction) return false;

			return IPlugin::LateInit();
		}

		bool Plugin::PreRun() {

			if (!preRunFunction) return false;

			return IPlugin::PreRun();
		}

		bool Plugin::PreRelease() {

			if (!preReleaseFunction) return false;

			return IPlugin::PreRelease();
		}

	}

}

#endif
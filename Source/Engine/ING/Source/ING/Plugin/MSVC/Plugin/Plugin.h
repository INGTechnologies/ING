#pragma once

#ifdef USE_MSVC

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#include <Windows.h>



namespace ING {

	class Engine;

	class PluginManager;



	namespace MSVC {

		class ING_API Plugin : public IPlugin {

			/**
			 *	Friend Class
			 */
		public:
			friend class PluginManager;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Plugin(const WString& path);
			~Plugin();



			/**
			 *	Release Method
			 */
		public:
			virtual bool Release() override;



			/**
			 *	Properties
			 */
		private:
			HMODULE						moduleHandle;

			DLL_DIRECTORY_COOKIE		dllDirCookie;



			/**
			 *	Methods
			 */
		public:
			virtual bool Load		()	override;
			virtual bool Unload		()	override;

			virtual bool LateCreate	()	override;

			virtual bool PreInit	()	override;
			virtual bool LateInit	()	override;

			virtual bool PreRun		()	override;

			virtual bool PreRelease	()	override;

		};

	}

}

#endif
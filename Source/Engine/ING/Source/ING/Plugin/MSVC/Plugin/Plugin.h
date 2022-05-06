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



	namespace MSVC {

		typedef bool (*PluginLoadFunction)		(ING::Engine* engine, ING::IPlugin* plugin);
		typedef bool (*PluginUnloadFunction)	();

		typedef void (*PluginLateCreateFunction)();
		typedef void (*PluginPreInitFunction)	();
		typedef void (*PluginLateInitFunction)	();
		typedef void (*PluginPreRunFunction)	();



		class ING_API Plugin : public IPlugin {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Plugin(const String& name, const WString& path);
			~Plugin();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			HMODULE						moduleHandle;

			PluginLoadFunction			loadFunction;
			PluginUnloadFunction		unloadFunction;

			PluginLateCreateFunction	lateCreateFunction;
			PluginPreInitFunction		preInitFunction;
			PluginLateInitFunction		lateInitFunction;
			PluginPreRunFunction		preRunFunction;



			/**
			 *	Methods
			 */
		public:
			virtual bool Load		()	override;
			virtual bool Unload		()	override;

			virtual void LateCreate	()	override;

			virtual void PreInit	()	override;
			virtual void LateInit	()	override;

			virtual void PreRun		()	override;

		};

	}

}

#endif
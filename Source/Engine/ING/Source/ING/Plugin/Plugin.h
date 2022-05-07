#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class IPlugin;
	class Engine;



	typedef bool (*PluginLoadFunction)		(ING::Engine* engine, ING::IPlugin* plugin);
	typedef bool (*PluginUnloadFunction)	();

	typedef void (*PluginLateCreateFunction)();
	typedef void (*PluginPreInitFunction)	();
	typedef void (*PluginLateInitFunction)	();
	typedef void (*PluginPreRunFunction)	();
	typedef void (*PluginPreReleaseFunction)();



	class ING_API IPlugin {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IPlugin(const String& name, const WString& path);
		~IPlugin();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String  name;
		WString path;
		bool	isLoaded;

	public:
		const String&	GetName() { return name; }
		const WString&	GetPath() { return path; }
		bool			IsLoaded() { return isLoaded; }

	protected:
		PluginLoadFunction			loadFunction;
		PluginUnloadFunction		unloadFunction;

		PluginLateCreateFunction	lateCreateFunction;
		PluginPreInitFunction		preInitFunction;
		PluginLateInitFunction		lateInitFunction;
		PluginPreRunFunction		preRunFunction;
		PluginPreReleaseFunction	preReleaseFunction;



		/**
		 *	Methods
		 */
	public:
		static IPlugin* Create(const String& name, const WString& path);

		virtual bool Load	();
		virtual bool Unload	();

		virtual void LateCreate();

		virtual void PreInit();
		virtual void LateInit();

		virtual void PreRun();

		virtual void PreRelease();

	};

}



/**
 *	Define Macros
 */
#ifdef IS_PLUGIN
#define DEFAULT_PLUGIN_LOAD(engine, plugin)\
		ING::Engine::LoadInstance(engine);\
		ING::PluginManager::LoadInstance(ING::Engine::GetInstance()->GetSquare<ING::PluginManager>());
#endif
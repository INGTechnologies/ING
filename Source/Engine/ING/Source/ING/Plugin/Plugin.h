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


	typedef ING::Utils::String (*PluginNameFunction)	();

	typedef bool (*PluginLoadFunction)		(ING::Engine* engine, ING::IPlugin* plugin);
	typedef bool (*PluginUnloadFunction)	();

	typedef bool (*PluginLateCreateFunction)();
	typedef bool (*PluginPreInitFunction)	();
	typedef bool (*PluginLateInitFunction)	();
	typedef bool (*PluginPreRunFunction)	();
	typedef bool (*PluginPreReleaseFunction)();



	class ING_API IPlugin {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IPlugin(const WString& path);
		~IPlugin();



		/**
		 *	Release Method
		 */
	public:
		virtual bool Release();



		/**
		 *	Properties
		 */
	protected:
		String  name;
		WString path;
		bool	isLoaded;

	public:
		const String&	GetName() { return name; }
		const WString&	GetPath() { return path; }
		bool			IsLoaded() { return isLoaded; }

	protected:
		PluginNameFunction			nameFunction;

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
		static IPlugin* Create(const WString& path);

		virtual bool Load	();
		virtual bool Unload	();

		virtual bool LateCreate();

		virtual bool PreInit();
		virtual bool LateInit();

		virtual bool PreRun();

		virtual bool PreRelease();

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

#define PLUGIN_STR(Str) \
Str

#define PLUGIN_EXPORTS(Name) \
PLUGIN_STR(Name)_EXPORTS

#define PLUGIN_API(Name) \
PLUGIN_STR(Name)_API

#define PLUGIN_PRIVATE_API(Name) \
PLUGIN_STR(Name)_PRIVATE_API

#define PLUGIN_EXTERN(Name) \
PLUGIN_STR(Name)_EXTERN

#define PLUGIN_FUNCTION(Name) \
extern "C" PLUGIN_API(Name)

#define DECLARE_PLUGIN(Name) \
extern "C" PLUGIN_PRIVATE_API(Name) ING::Utils::String PluginName();\
PLUGIN_FUNCTION(Name) ING::Utils::String PLUGIN_STR(Name)_Name();

#define DEFINE_PLUGIN(Name) \
ING::Utils::String PluginName(){ return #Name; }\
ING::Utils::String PLUGIN_STR(Name)_Name(){ return #Name; }

#define DECLARE_PLUGIN_FUNCTION(PluginName, ReturnType, FunctionName) \
PLUGIN_FUNCTION(PluginName) ReturnType PLUGIN_STR(PLUGIN_STR(PluginName)_)FunctionName

#define DEFINE_PLUGIN_FUNCTION(PluginName, ReturnType, FunctionName) \
ReturnType PLUGIN_STR(PLUGIN_STR(PluginName)_)FunctionName



/**
 *	Add This To Plugin Entry Point And Replace <Name> To Your Plugin Name
 */
 /* 
 #if PLUGIN_EXPORTS(<Name>) > 0
 #define <Name>_API __declspec(dllexport)
 #define <Name>_PRIVATE_API __declspec(dllexport)
 #define <Name>_EXTERN
 #else
 #define <Name>_API __declspec(dllimport)
 #ifndef IS_PLUGIN
 #define <Name>_PRIVATE_API __declspec(dllimport)
 #else
 #define <Name>_PRIVATE_API
 #endif
 #define <Name>_EXTERN extern
 #endif
 */
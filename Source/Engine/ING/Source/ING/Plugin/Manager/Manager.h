#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class IPlugin;



	class ING_API PluginManager :
		public Singleton<PluginManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		PluginManager();
		~PluginManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();



		/**
		 *	Properties
		 */
	private:
		std::unordered_map<String, void*> name2PointerMap;

		std::unordered_map<String, IPlugin*> name2PluginMap;

		List<IPlugin*> pluginList;

	public:
		void		SetPointer		(const String& name, void* pointer);
		bool		IsHasPointer	(const String& name);
		void*		GetPointer		(const String& name);
		void		RemovePointer	(const String& name);

		IPlugin*	GetPlugin		(const String& name) { if(!IsHasPlugin(name)) return 0; return name2PluginMap[name]; }
		bool		IsHasPlugin		(const String& name) { return name2PluginMap.find(name) != name2PluginMap.end(); }

		const List<IPlugin*>& GetPluginList() { return pluginList; }



		/**
		 *	Methods
		 */
	public:
		bool		LoadPlugins(const WString& path);

		List<IPlugin*>::Node* AddPlugin	(IPlugin* plugin);
		void		RemovePlugin(IPlugin* plugin);

		bool		LateCreate	();
		bool		PreInit		();
		bool		LateInit	();
		bool		PreRun		();
		bool		PreRelease	();

	};

}
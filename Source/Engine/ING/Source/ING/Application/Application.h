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

	class Configuration;

	class ApplicationReflectionSystem;

	class ApplicationWindowSystem;

	class ApplicationRenderingSystem;

	class ApplicationUISystem;

	class ApplicationActorSystem;

	class IApplicationComponent;

	class IApplicationModule;



	class ING_API IApplication
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class ApplicationManager;
		friend class IApplicationComponent;



		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplication	(const WString& configPath);
		~IApplication	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init	();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String						name;

	protected:
		WString						configPath;

	private:
		Configuration*				configuration;

		ApplicationReflectionSystem*reflectionSystem;

		ApplicationWindowSystem*	windowSystem;

		ApplicationRenderingSystem*	renderingSystem;

		ApplicationUISystem*		uiSystem;

		ApplicationActorSystem*		actorSystem;

		std::unordered_map<String, unsigned int> name2ComponentIndexMap;
		std::vector<IApplicationComponent*> componentVector;

		std::unordered_map<String, IApplicationModule*> name2ModuleMap;

		std::vector<IApplicationModule*> sortedModuleVector;

	public:
		const String&				GetName			() { return name; }

		const WString&				GetConfigPath	() { return configPath; }

		Configuration*				GetConfiguration() {return configuration; }

		ApplicationReflectionSystem*GetReflectionSystem() { return reflectionSystem; }

		ApplicationWindowSystem*	GetWindowSystem	() { return windowSystem; }

		ApplicationRenderingSystem*	GetRenderingSystem() { return renderingSystem; }

		ApplicationUISystem*		GetUISystem		() { return uiSystem; }

		ApplicationActorSystem*		GetActorSystem		() { return actorSystem; }

		bool						IsHasComponent	(const String& name) { return name2ComponentIndexMap.find(name) != name2ComponentIndexMap.end(); }

		unsigned int				GetComponentIndex(const String& name) { return name2ComponentIndexMap[name]; }

		IApplicationComponent*		GetComponent	(const String& name) { return componentVector[name2ComponentIndexMap[name]]; }

		IApplicationComponent*		GetComponent	(unsigned int index) { return componentVector[index]; }

		const std::unordered_map<String, IApplicationModule*>& GetName2ModuleMap () { return name2ModuleMap; }

		bool						IsHasModule(const String& moduleName) { return name2ModuleMap.find(moduleName) != name2ModuleMap.end(); }

		IApplicationModule*			GetModule(const String& moduleName) { if (!IsHasModule(moduleName)) return 0; return name2ModuleMap[moduleName]; }

		const std::vector<IApplicationModule*>& GetSortedModuleVector () { return sortedModuleVector; }



		/**
		 *	Methods
		 */
	public:
		unsigned int				GetModuleLevel(IApplicationModule* module);
		void						SortModuleVector();

		void						AddComponent	(IApplicationComponent* component);
		void						RemoveComponent	(IApplicationComponent* component);

		virtual void				Start();

		virtual void				PreUpdate();
		virtual void				Update();
		virtual void				LateUpdate();

		virtual void				PreRender();
		virtual void				Render();
		virtual void				LateRender();

		void						AddModule(IApplicationModule* module);
		void						RemoveModule(IApplicationModule* module);

	};

}
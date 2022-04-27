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

	class ApplicationWindowManager;

	class IApplicationComponent;

	namespace Rendering {

		class System;

	}



	class ING_API IApplication
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class ApplicationManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplication	(const std::string& configPath);
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
		std::string					name;

		std::string					configPath;

		Configuration*				configuration;

		ApplicationWindowManager*	windowManager;

		Rendering::System*			renderingSystem;

		std::unordered_map<std::string, unsigned int> name2ComponentIndexMap;
		std::vector<IApplicationComponent*> componentVector;

	public:
		const std::string&			GetName			() { return name; }

		const std::string&			GetConfigPath	() { return configPath; }

		Configuration*				GetConfiguration() {return configuration; }

		ApplicationWindowManager*	GetWindowManager() { return windowManager; }

		Rendering::System*			GetSystem		() { return renderingSystem; }

		IApplicationComponent*		GetComponent	(const std::string& name) { return componentVector[name2ComponentIndexMap[name]]; }

		IApplicationComponent*		GetComponent	(unsigned int index) { return componentVector[index]; }



		/**
		 *	Methods
		 */
	public:
		void			AddComponent	(IApplicationComponent* component);
		void			RemoveComponent	(IApplicationComponent* component);

		virtual void	Start();

		virtual void	PreUpdate();
		virtual void	Update();
		virtual void	LateUpdate();

		virtual void	PreRender();
		virtual void	Render();
		virtual void	LateRender();

	};

}
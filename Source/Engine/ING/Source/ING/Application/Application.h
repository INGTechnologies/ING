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
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		std::string					name;

		std::string					configPath;

		Configuration*				configuration;

		ApplicationWindowManager*	windowManager;

	public:
		const std::string&			GetName			() { return name; }

		const std::string&			GetConfigPath	() { return configPath; }

		Configuration*				GetConfiguration() {return configuration; }

		ApplicationWindowManager*	GetWindowManager() { return windowManager; }



		/**
		 *	Methods
		 */
	public:
		virtual void	Start();

		virtual void	PreUpdate();
		virtual void	Update();
		virtual void	LateUpdate();

		virtual void	PreRender();
		virtual void	Render();
		virtual void	LateRender();

	};

}
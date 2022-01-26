#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Application State
 */
#include <ING/Application/State/State.h>



namespace ING {

	class Configuration;

	class ING_API Application: public Board<Application> {	

		/**
		 *	Constructors And Destructor
		 */
	public:
		Application();
		~Application();



		/**
		 *	Init, Run, Release, Create Methods
		 */
	public:
		virtual bool			Init()		override;
		virtual bool			Run()		override;
		virtual bool			Release()	override;



		/**
		 *	Configuration
		 */
	private:
		Configuration* configuration;

	public:
		Configuration* GetConfiguration() {

			return configuration;

		}

		void LoadConfiguration();



		/**
		 *	State
		 */
	private:
		ApplicationState state;

	public:
		ApplicationState GetState() { return state; }

	};



	/**
	 *	Define Macros
	 */
	#define ING_CREATE_APPLICATION	IMPLEMENT_SINGLETON(ING::Application);
	#define ING_INIT_APPLICATION	if(!ING::Application::GetInstance()->Init()){return 1;}
	#define ING_RUN_APPLICATION		if(!ING::Application::GetInstance()->Run()){return 1;}

}
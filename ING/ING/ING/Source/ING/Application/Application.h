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



namespace ING {

	class ING_API Application: public Board<Application> {	

		/**
		 *	Constructors And Destructor
		 */
	public:
		Application();
		~Application();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};



	/**
	 *	Define Macros
	 */
	#define ING_CREATE_APPLICATION	IMPLEMENT_SINGLETON(ING::Application);
	#define ING_INIT_APPLICATION	if(!ING::Application::GetInstance()->Init()){return 1;}
	#define ING_RUN_APPLICATION		if(!ING::Application::GetInstance()->Run()){return 1;}

}
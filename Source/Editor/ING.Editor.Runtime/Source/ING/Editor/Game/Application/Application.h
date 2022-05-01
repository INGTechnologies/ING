#pragma once

/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include IOStream
 */
#include <iostream>



namespace ING {

	namespace Editor {

		class Application;



		class GameApplication :
			public IApplication,
			Singleton<GameApplication>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			GameApplication	(const WString& configPath);
			~GameApplication();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;

		};

	}

}
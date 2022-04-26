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
			GameApplication	(const std::string& configPath);
			~GameApplication();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;

		};

	}

}
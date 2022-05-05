#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



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



		class ING_API GameApplication :
			public IApplication,
			public Singleton<GameApplication>
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class Singleton<GameApplication>;



			/**
			 *	Constructors And Destructor
			 */
		private:
			GameApplication();

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
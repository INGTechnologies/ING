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

		class GameApplication;



		class Application :
			public IApplication,
			Singleton<Application>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Application(const std::string& configPath, const std::string& gamePath);
			~Application();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			GameApplication*	gameApplication;

			std::string			projectPath;

		public:
			GameApplication*	GetGameApplication() { return gameApplication; }

			const std::string&	GetProjectPath() { return projectPath; }



			/**
			 *	Methods
			 */
		private:
			void	SetupRootPaths();

			void	CreateMainWindow();

			void	CreateGameApplication();

			virtual void PlayGame();

		};

	}

}
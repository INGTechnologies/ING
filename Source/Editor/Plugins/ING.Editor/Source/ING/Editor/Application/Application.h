#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING/Editor/EntryPoint/EntryPoint.h>



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



		class ING_EDITOR_API Application :
			public IApplication,
			public Singleton<Application>
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class Singleton<Application>;



			/**
			 *	Constructors And Destructor
			 */
		private:
			Application();

		public:
			Application(const WString& configPath, const WString& gamePath);
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

			WString				projectPath;

		public:
			GameApplication*	GetGameApplication() { return gameApplication; }

			const WString&		GetProjectPath() { return projectPath; }



			/**
			 *	Methods
			 */
		private:
			void				SetupRootPaths();

			void				CreateMainWindow();

			void				CreateGameApplication();

			bool				InitGameApplication();

			virtual void		PlayGame();

		};

	}

}
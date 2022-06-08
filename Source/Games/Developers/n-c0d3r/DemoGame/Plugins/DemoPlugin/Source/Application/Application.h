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

	class IGameApplication;



	namespace Editor {

		class Layout;



		class PLUGIN_API(ING_EDITOR) Application :
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
			IGameApplication*	gameApplication;

			WString				projectPath;

		public:
			IGameApplication*	GetGameApplication() { return gameApplication; }

			const WString&		GetProjectPath() { return projectPath; }



			/**
			 *	Methods
			 */
		private:
			void				SetupRootPaths();

			void				CreateGameApplication();

			bool				InitGameApplication();

			virtual void		PlayGame();

		};

	}

}
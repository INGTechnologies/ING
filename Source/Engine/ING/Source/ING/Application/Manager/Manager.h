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

	class Screen;

	class IApplication;

	class IApplicationModule;



	class ING_API ApplicationManager :
		public Singleton<ApplicationManager>,
		public Square
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class IApplicationModule;



		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationManager	();
		~ApplicationManager	();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();



		/**
		 *	Properties
		 */
	private:
		std::unordered_map<String, IApplication*> name2ApplicationMap;
		IApplication*	gameApplication;

		std::unordered_map<String, unsigned int> name2ModuleInstanceCount;

	public:
		IApplication*	GetApplication			(const String& name) { return name2ApplicationMap[name]; }
		IApplication*	GetGameApplication		(){ return gameApplication; }
		void			SetGameApplication		(IApplication* gameApplication){ this->gameApplication = gameApplication; }

		bool			IsHasModule(const String& name) {
			return name2ModuleInstanceCount.find(name) != name2ModuleInstanceCount.end();
		}

		unsigned int	GetModuleInstanceCount(const String& name) {

			if (!IsHasModule(name)) { return 0; }

			return name2ModuleInstanceCount[name];
		}



		/**
		 *	Methods
		 */
	public:
		void			AddApplication		(IApplication* app);
		void			RemoveApplication	(IApplication* app);

		void			Start();

		void			PreUpdate();
		void			Update();
		void			LateUpdate();

		void			PreRender();
		void			Render();
		void			LateRender();

	};

}
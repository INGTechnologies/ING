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



	class ING_API ApplicationManager :
		public Singleton<ApplicationManager>,
		public Square
	{

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

	public:
		IApplication*	GetApplication(const String& name) { return name2ApplicationMap[name]; }



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
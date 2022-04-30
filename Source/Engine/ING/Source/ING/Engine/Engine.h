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
 *	Include Engine State
 */
#include <ING/Engine/State/State.h>



/**
 *	Include Event Storage
 */
#include <ING/Event/Storage/Storage.h>



namespace ING {

	class Configuration;

	class ConfigurationCompiler;



	class ING_API Engine: 
		public Board<Engine>,
		public EventStorage
	{	

		/**
		 *	Constructors And Destructor
		 */
	public:
		Engine();
		~Engine();



		/**
		 *	Init, Run, Release, Shutdown Methods
		 */
	public:
		virtual bool	Init()		override;
		virtual bool	Run()		override;
		virtual bool	Release()	override;
				void	Shutdown();



		/**
		 *	Properties
		 */
	private:
		WString			gameDir;
		WString			workingDir;
		String			name;

		std::unordered_map<WString, WString> rootPath2AbsolutePath;

		EngineState		state;

		Configuration*	configuration;

	public:
		const WString&	GetGameDir					() { return gameDir; }
		const WString&	GetWorkingDir				() { return workingDir; }
		const String&	GetName						() { return name; }

		const WString&	GetRootPath					(const WString& rootPath) { return rootPath2AbsolutePath[rootPath]; }
		bool			IsHaveRootPath				(const WString& rootPath) { return rootPath2AbsolutePath.find(rootPath) != rootPath2AbsolutePath.end(); }
		void			SetRootPath					(const WString& name, const WString& value) {

			rootPath2AbsolutePath[name] = value;

		}

		EngineState		GetState					() { return state; }

		Configuration*	GetConfiguration			() { return configuration; }



		/**
		 *	Methods
		 */
	public:
		void			FrameUpdate();

	};



	/**
	 *	Define Macros
	 */
	#define ING_CREATE_ENGINE		IMPLEMENT_SINGLETON( ING::Engine );
	#define ING_INIT_ENGINE			if ( !ING::Engine::GetInstance()->Init() )	{ return 1; }
	#define ING_RUN_ENGINE			if ( !ING::Engine::GetInstance()->Run()  )	{ return 1; }

	#define ING_ENGINE_CONFIG_PROP(T, name, value) \
\
	if (!ING::Engine::GetInstance()->GetConfiguration()->Exist(name)) {\
\
		ING::Engine::GetInstance()->GetConfiguration()->Add<T>(name);\
\
		ING::Engine::GetInstance()->GetConfiguration()->Set<T>(name, value);\
\
	}\
	else\
	{\
\
\
\
	}\

#define ING_ENGINE_SET_CONFIG_PROP(T, name, value) \
\
	ING::Engine::GetInstance()->GetConfiguration()->Set<T>(name, value);\
\

#define ING_ENGINE_GET_CONFIG_PROP(T, name) \
\
	ING::Engine::GetInstance()->GetConfiguration()->Get<T>(name);\
\

}
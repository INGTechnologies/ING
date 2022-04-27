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
		virtual bool			Init()		override;
		virtual bool			Run()		override;
		virtual bool			Release()	override;
				void			Shutdown();



		/**
		 *	Properties
		 */
	private:
		std::string			gameDir;
		std::wstring		gameDir_wstr;
		std::string			workingDir;
		std::wstring		workingDir_wstr;
		std::string			name;

		std::unordered_map<std::wstring, std::wstring> rootPath2AbsolutePath;

		void*				programHandle;

		EngineState			state;

		Configuration*		configuration;

	public:
		const std::string&	GetGameDir					() { return gameDir; }
		const std::string&	GetWorkingDir				() { return workingDir; }
		const std::wstring& GetGameDir_WSTR				() { return gameDir_wstr; }
		const std::wstring& GetWorkingDir_WSTR			() { return workingDir_wstr; }
		const std::string&	GetName						() { return name; }

		const std::wstring& GetAbsolutePathFromRootPath	(const std::wstring& rootPath) { return rootPath2AbsolutePath[rootPath]; }
		bool				IsHaveRootPath				(const std::wstring& rootPath) { return rootPath2AbsolutePath.find(rootPath) != rootPath2AbsolutePath.end(); }

		void*				GetProgramHandle			() { return programHandle; }
		void				SetProgramHandle			(void* programHandle) { this->programHandle = programHandle; }

		EngineState			GetState					() { return state; }

		Configuration*		GetConfiguration			() { return configuration; }



		/**
		 *	Methods
		 */
	public:
		void FrameUpdate();

		void AddRootPath(const std::wstring& name, const std::wstring& value);

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

#define ING_ENGINE_GET_CONFIG_PROP(T, name, value) \
\
	ING::Engine::GetInstance()->GetConfiguration()->Get<T>(name);\
\

}
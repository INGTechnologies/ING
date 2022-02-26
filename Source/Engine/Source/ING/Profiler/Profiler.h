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
 *	Include Unordered Map
 */
#include <unordered_map>



namespace ING {

	class ProfilerSession;



	class ING_API Profiler :
		public Square,
		public Singleton<Profiler>
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Profiler();
		~Profiler();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Properties
		 */
	private:
		std::map<std::pair<std::string, std::string>, ProfilerSession*> sessionMap;

		bool logSessionInConsole;

	public:
		bool IsLogSessionInConsole() { return logSessionInConsole; }



		/**
		 *	Methods
		 */
	public:
		static ProfilerSession* BeginSession	(std::string name, std::string category);
		static ProfilerSession* BeginSession	(const char* name, const char* category);

		static void				EndSession		(std::string name, std::string category);
		static void				EndSession		(const char* name, const char* category);

	};


}
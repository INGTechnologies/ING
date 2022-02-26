
/**
 *	Include Header
 */
#include "Profiler.h"



/**
 *	Include Profiler Session
 */
#include "Session/Session.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Profiler::Profiler() {

		APPLICATION_CONFIG_PROP(bool, "ING::Profiler::logSessionInConsole", true);

	}

	Profiler::~Profiler() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Profiler::Init() {

		logSessionInConsole = APPLICATION_GET_CONFIG_PROP(bool, "ING::Profiler::logSessionInConsole");

		return true;
	}

	bool Profiler::Run() {



		return true;
	}

	bool Profiler::Release() {



		return true;
	
	}



	/**
	 *	Methods
	 */
	ProfilerSession* Profiler::BeginSession	(std::string name, std::string category)	{

		ProfilerSession* session = new ProfilerSession(name, category);

		Profiler::GetInstance()->sessionMap[std::pair<std::string, std::string>(name, category)] = session;

		if (Profiler::GetInstance()->logSessionInConsole) {

			Debug::SetConsoleColor(0x30);

			std::wcout << " ";

			std::cout << String("Begin Session ");

			Debug::SetConsoleColor(0x07);

			std::wcout << " ";



			Debug::SetConsoleColor(0x07);

			std::cout << String("(");

			Debug::SetConsoleColor(0x08);

			std::cout << String(" Name: ");

			Debug::SetConsoleColor(0x07);

			std::cout << String("'") + name + String("'");



			Debug::SetConsoleColor(0x07);

			std::cout << String(",");

			Debug::SetConsoleColor(0x08);

			std::cout << String(" Category: ");

			Debug::SetConsoleColor(0x07);

			std::cout << String("'") + category + String("'");



			Debug::SetConsoleColor(0x07);

			std::cout << String(" )") << std::endl;

		}

		return session;

	}
	ProfilerSession* Profiler::BeginSession	(const char* name, const char* category)	{ return BeginSession	(String(name), String(category)); }

	void			 Profiler::EndSession	(std::string name, std::string category)	{

		ProfilerSession* session = Profiler::GetInstance()->sessionMap[std::pair<std::string, std::string>(name, category)];

		session->End();

		if (Profiler::GetInstance()->logSessionInConsole) {

			float completeTime = session->GetCompleteTime().count();

			Debug::SetConsoleColor(0x20);

			std::wcout << " ";

			std::cout << String("End   Session ");

			Debug::SetConsoleColor(0x07);

			std::wcout << " ";



			Debug::SetConsoleColor(0x07);

			std::cout << String("(");

			Debug::SetConsoleColor(0x08);

			std::cout << String(" Name: ");

			Debug::SetConsoleColor(0x07);

			std::cout << String("'") + name + String("'");



			Debug::SetConsoleColor(0x07);

			std::cout << String(",");

			Debug::SetConsoleColor(0x08);

			std::cout << String(" Category: ");

			Debug::SetConsoleColor(0x07);

			std::cout << String("'") + category + String("'");



			Debug::SetConsoleColor(0x07);

			std::cout << String(",");

			Debug::SetConsoleColor(0x08);

			std::cout << String(" Complete Time: ");

			Debug::SetConsoleColor(0x0A);

			std::cout << String(completeTime * 1000) + String("ms");



			Debug::SetConsoleColor(0x07);

			std::cout << String(" )") << std::endl;
			
			//std::cout << String("( Name: '") + name + String("', Category: '") + category + String("', Complete Time: ") + String(completeTime * 1000) + String("ms)") << std::endl;
			
			//std::cout << String("( Name: '") + name + String("', Category: '") + category + String("', Complete Time: ") + String(completeTime * 1000) + String("ms)") << std::endl;

		}

		Profiler::GetInstance()->sessionMap.erase(std::pair<std::string, std::string>(name, category));

		delete session;

	}
	void			 Profiler::EndSession	(const char* name, const char* category)	{ return EndSession		(String(name), String(category)); }


}

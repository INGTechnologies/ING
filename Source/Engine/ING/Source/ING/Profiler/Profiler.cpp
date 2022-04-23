
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

		Debug::Log("Start Creating Profiler");

		APPLICATION_CONFIG_PROP(bool, "ING.Profiler.logSessionInConsole", true);

		Debug::Log("Profiler Created");

	}

	Profiler::~Profiler() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Profiler::Init() {

		Debug::Log("Start Initializing Profiler");

		logSessionInConsole = APPLICATION_GET_CONFIG_PROP(bool, "ING.Profiler.logSessionInConsole");

		Debug::Log("Profiler Initialized");

		return true;
	}

	bool Profiler::Run() {

		Debug::Log("Start Running Profiler");

		return true;
	}

	bool Profiler::Release() {

		Debug::Log("Start Releasing Profiler");

		Debug::Log("Finished Releasing Profiler");

		return true;
	
	}



	/**
	 *	Methods
	 */
	ProfilerSession*				Profiler::BeginSession	(const std::string& name, const std::string& category)	{

		ProfilerSession* session = new ProfilerSession(name, category);

		Profiler* profiler = Profiler::GetInstance();

		profiler->sessionMap[std::pair<std::string, std::string>(name, category)] = session;

		if (Profiler::GetInstance()->logSessionInConsole) {

			Debug::SetConsoleColor(0xF0);

			std::wcout << " BEGIN ";

			Debug::SetConsoleColor(0x20);

			std::cout << String(" SESSION ");

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
	ProfilerSession*				Profiler::BeginSession	(const char* name, const char* category)	{ return BeginSession	(String(name), String(category)); }

	void							Profiler::EndSession	(const std::string& name, const std::string& category)	{

		ProfilerSession* session = Profiler::GetInstance()->sessionMap[std::pair<std::string, std::string>(name, category)];

		session->End();

		if (Profiler::GetInstance()->logSessionInConsole) {

			float completeTime = session->GetCompleteTime().count();

			Debug::SetConsoleColor(0x70);

			std::wcout << "  END  ";

			Debug::SetConsoleColor(0x20);

			std::cout << String(" SESSION ");

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

		}

		Profiler::GetInstance()->sessionMap.erase(std::pair<std::string, std::string>(name, category));

		delete session;

	}
	void							Profiler::EndSession	(const char* name, const char* category)	{ return EndSession		(String(name), String(category)); }

	List<ProfilerSession*>::Node*	Profiler::AddSession	(ProfilerSession* session) {

		if (category2SessionListMap.find(session->GetCategory()) == category2SessionListMap.end()) {

			category2SessionListMap[session->GetCategory()] = new List<ProfilerSession*>();

		}

		return category2SessionListMap[session->GetCategory()].Add(session);

	}

	void							Profiler::RemoveSession	(ProfilerSession* session) {

		category2SessionListMap[session->GetCategory()].Remove(session->GetNode());

		if (category2SessionListMap[session->GetCategory()].GetSize() == 0) {

			category2SessionListMap[session->GetCategory()].ReleasePtr();

			category2SessionListMap.erase(session->GetCategory());

		}

	}

}


/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include CSharp Language
 */
#include <ING/Scripting/CSharp/Language/Language.h>



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		Manager::Manager()
		{

			Debug::Log("Start Creating Scripting::Manager");

			AddLanguage(new CSharp::Language());

			Debug::Log("Scripting::Manager Created");

		}

		Manager::~Manager()
		{



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool Manager::Init()
		{

			Debug::Log("Start Initializing Scripting::Manager");

			for (auto item : name2LanguageMap) {

				item.second->Init();

			}

			Debug::Log("Scripting::Manager Initialized");

			return true;
		}

		bool Manager::Run()
		{

			Debug::Log("Start Running Scripting::Manager");

			return true;
		}

		bool Manager::Release()
		{

			Debug::Log("Start Releasing Scripting::Manager");

			for (auto item = name2LanguageMap.begin(); item != name2LanguageMap.end();) {

				(item++)->second->Release();

			}

			delete this;

			Debug::Log("Finished Releasing Scripting::Manager");

			return true;
		}



		/**
		 *	Methods
		 */
		void Manager::AddLanguage		(ILanguage* language) {

			name2LanguageMap[language->GetName()] = language;

		}

		void Manager::RemoveLanguage	(ILanguage* language) {

			name2LanguageMap.erase(language->GetName());

		}

	}

}
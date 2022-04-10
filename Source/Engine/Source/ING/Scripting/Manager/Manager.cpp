
/**
 *	Include Header
 */
#include "Manager.h"



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

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		Manager::Manager()
		{

			Debug::Log("Start Creating Scripting::Manager");



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

			delete this;

			Debug::Log("Finished Releasing Scripting::Manager");

			return true;
		}

	}

}
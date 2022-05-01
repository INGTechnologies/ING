
/**
 *	Include Header
 */
#include "Engine.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



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



namespace ING { 

	namespace UI {

		/**
		 *	Constructors And Destructor
		 */
		Engine::Engine()
		{

			Debug::Log("Start Creating UI::Engine");



			Debug::Log("UI::Engine Created");

		}

		Engine::~Engine()
		{



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool Engine::Init()
		{

			Debug::Log("Start Initializing UI::Engine");



			Debug::Log("UI::Engine Initialized");

			return true;
		}

		bool Engine::Run()
		{

			Debug::Log("Start Running UI::Engine");

			return true;
		}

		bool Engine::Release()
		{

			Debug::Log("Start Releasing UI::Engine");

			delete this;

			Debug::Log("Finished Releasing UI::Engine");

			return true;
		}

	}

}
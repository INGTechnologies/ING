
/** 
 *	Include Header
 */
#include "GameFramework.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	GameFramework::GameFramework() {

		Debug::Log("Start Creating GameFramework");


		Debug::Log("GameFramework Created");

	}

	GameFramework::~GameFramework() {



	}



	/**
		*	Init, Run, Release Methods
		*/
	bool GameFramework::Init() {

		Debug::Log("Start Initializing GameFramework");

		bool result = Board<GameFramework>::Init();

		if (result)
			Debug::Log("GameFramework Initialized");
		else {

			Debug::Error("Cant Init GameFramework");

		}

		return result;
	}

	bool GameFramework::Run() {

		Debug::Log("Start Running GameFramework");

		return Board<GameFramework>::Run();
	}

	bool GameFramework::Release() {

		Debug::Log("Start Releasing GameFramework");

		bool result = Board<GameFramework>::Release();

		if (result)
			Debug::Log("Finished Releasing GameFramework");
		else {

			Debug::Error("Cant Release GameFramework");

		}

		return result;
	}

}
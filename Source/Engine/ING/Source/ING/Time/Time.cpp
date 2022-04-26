
/**
 *	Include Header
 */
#include "Time.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



static auto appStart = std::chrono::steady_clock::now();



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Time::Time() {

		Debug::Log("Start Creating Time");

		Debug::Log("Time Created");

	}

	Time::~Time() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Time::Init() {

		Debug::Log("Start Initializing Time");

		deltaTime = 0;

		Debug::Log("Time Initialized");

		return true;
	}

	bool Time::Run() {

		Debug::Log("Start Running Time");

		return true;
	}

	bool Time::Release() {

		Debug::Log("Start Releasing Time");

		Debug::Log("Finished Releasing Time");

		return true;
	}



	/**
	 *	Start, End Methods
	 */
	void Time::StartFrame() {

		frameStart = std::chrono::steady_clock::now() - appStart;

	}

	void Time::EndFrame() {

		frameEnd = std::chrono::steady_clock::now() - appStart;

		deltaTime = (float)((long double)(frameEnd - frameStart).count());

	}



	/**
	 *	Properties
	 */
	float Time::GetDeltaTime() {

		return Time::GetInstance()->deltaTime;
	}

	float Time::GetFPS() {

		return 1.0f / GetDeltaTime();
	}

}

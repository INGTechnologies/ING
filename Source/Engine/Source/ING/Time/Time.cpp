
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



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Time::Time() {



	}

	Time::~Time() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Time::Init() {

		deltaTime = 0;

		return true;
	}

	bool Time::Run() {



		return true;
	}

	bool Time::Release() {



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

		deltaTime = (frameEnd - frameStart).count();

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

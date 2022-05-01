
/**
 *	Include Header
 */
#include "Session.h"



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h>



static auto appStart = std::chrono::steady_clock::now();



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ProfilerSession::ProfilerSession	(String name, String category) {

		this->name		= name;

		this->category	= category;

		startTime		= std::chrono::steady_clock::now() - appStart;

		node = Profiler::GetInstance()->AddSession(this);

	}

	ProfilerSession::~ProfilerSession	() {



	}



	/**
	 *	Methods
	 */
	void	ProfilerSession::End	() {

		endTime = std::chrono::steady_clock::now() - appStart;

		completeTime = (endTime - startTime);

		Profiler::GetInstance()->RemoveSession(this);

	}

	float	ProfilerSession::CheckTime				() {

		return ((std::chrono::steady_clock::now() - appStart) - startTime).count();

	}

}
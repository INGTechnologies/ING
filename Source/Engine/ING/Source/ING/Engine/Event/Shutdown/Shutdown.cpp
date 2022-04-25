
/**
 *	Include Header
 */
#include "Shutdown.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EngineShutdownEvent::EngineShutdownEvent() {



	}

	EngineShutdownEvent::~EngineShutdownEvent() {



	}



	/**
	 *	Name
	 */
	std::string EngineShutdownEvent::GetName() { return "SHUTDOWN"; };

}

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
	String EngineShutdownEvent::GetName() { return "SHUTDOWN"; };

}
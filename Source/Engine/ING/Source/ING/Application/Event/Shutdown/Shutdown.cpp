
/**
 *	Include Header
 */
#include "Shutdown.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationShutdownEvent::ApplicationShutdownEvent() {



	}

	ApplicationShutdownEvent::~ApplicationShutdownEvent() {



	}



	/**
	 *	Name
	 */
	std::string ApplicationShutdownEvent::GetName() { return "SHUTDOWN"; };

}

/**
 *	Include Header
 */
#include "Configuration.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationConfiguration::ApplicationConfiguration() {



	}

	ApplicationConfiguration::~ApplicationConfiguration() {

		for (auto& it : ptrMap) {

			delete it.second;

		}

		ptrMap.clear();

	}

}
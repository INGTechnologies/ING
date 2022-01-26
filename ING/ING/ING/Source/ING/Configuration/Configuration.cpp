
/**
 *	Include Header
 */
#include "Configuration.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Configuration::Configuration() {



	}

	Configuration::~Configuration() {

		for (auto& it : ptrMap) {

			delete it.second;

		}

		ptrMap.clear();

	}

}
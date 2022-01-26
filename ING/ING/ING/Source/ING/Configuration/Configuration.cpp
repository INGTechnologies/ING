
/**
 *	Include Header
 */
#include "Configuration.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Configuration::Configuration() {

		/**
		 *	Add Default Properties
		 */
		Add<bool>("ING::Application::autoCreateWindow");

		Set<bool>("ING::Application::autoCreateWindow", true);

	}

	Configuration::~Configuration() {

		for (auto& it : ptrMap) {

			delete it.second;

		}

		ptrMap.clear();

	}

}
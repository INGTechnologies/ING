
/**
 *	Include Header
 */
#include "Configuration.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationConfiguration::ApplicationConfiguration() {

		/**
		 *	Add Default Properties
		 */
		Add<bool>("ING::Application::autoCreateWindow");

		Set<bool>("ING::Application::autoCreateWindow", true);

	}

	ApplicationConfiguration::~ApplicationConfiguration() {

		for (auto& it : ptrMap) {

			delete it.second;

		}

		ptrMap.clear();

	}

}
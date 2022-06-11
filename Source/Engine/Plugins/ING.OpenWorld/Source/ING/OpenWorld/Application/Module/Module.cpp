
/**
 *	Include Header
 */
#include "Module.h"



namespace ING {

	namespace OpenWorld {

		/**
		 *	Constructor And Destructors
		 */
		ApplicationModule::ApplicationModule(const String& name) :
			IApplicationModule(name)
		{



		}

		ApplicationModule::~ApplicationModule() {



		}



		/**
		 *	Release Methods
		 */
		void ApplicationModule::Release() {

			IApplicationModule::Release();

		}

	}

}
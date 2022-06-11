#pragma once

/**
 *	Include Plugin
 */
#include <ING/OpenWorld/Plugin/Plugin.h>



/**
 *	Include ApplicationModule
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace OpenWorld {

		class PLUGIN_API(ING_OPENWORLD) ApplicationModule : public IApplicationModule {

			/**
			 *	Constructor And Destructors
			 */
		public:
			ApplicationModule(const String & name);
			~ApplicationModule();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
#pragma once

/**
 *	Include Plugin
 */
#include <ING/StandardRP/Plugin/Plugin.h>



/**
 *	Include ApplicationModule
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace StandardRP {

		class PLUGIN_API(ING_STANDARDRP) ApplicationModule : public IApplicationModule {

			/**
			 *	Constructor And Destructors
			 */
		public:
			ApplicationModule	(IApplication* application);
			~ApplicationModule	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
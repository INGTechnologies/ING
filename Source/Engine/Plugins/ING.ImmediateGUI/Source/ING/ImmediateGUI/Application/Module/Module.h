#pragma once

/**
 *	Include Plugin
 */
#include <ING/ImmediateGUI/Plugin/Plugin.h>



/**
 *	Include ApplicationModule
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace ImmediateGUI {

		class PLUGIN_API(ING_IMMEDIATEGUI) ApplicationModule : public IApplicationModule {

			/**
			 *	Constructor And Destructors
			 */
		public:
			ApplicationModule	(IApplication * application);
			~ApplicationModule	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
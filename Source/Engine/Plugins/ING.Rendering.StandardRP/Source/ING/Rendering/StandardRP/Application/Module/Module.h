#pragma once

/**
 *	Include Plugin
 */
#include <ING/Rendering/StandardRP/Plugin/Plugin.h>



/**
 *	Include ApplicationModule
 */
#include <ING/Application/Module/Module.h>



namespace ING {

	namespace Rendering {

		namespace StandardRP {

			class PLUGIN_API(ING_RENDERING_STANDARDRP) ApplicationModule : public IApplicationModule {

				/**
				 *	Constructor And Destructors
				 */
			public:
				ApplicationModule	(const String& name);
				~ApplicationModule	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release();

			};

		}

	}

}
#pragma once

#include <ING/Rendering/StandardRP/EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



/**
 *	Declare Classes
 */
namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Info
 */
DECLARE_PLUGIN(ING_RENDERING_STANDARDRP);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, Load)		(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, PreInit)	();
DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, LateInit)	();

DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_RENDERING_STANDARDRP, bool, PreRelease)	();
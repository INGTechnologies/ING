#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include BindFlag
 */
#include <ING/Rendering/API/BindFlag/BindFlag.h>



/**
 *	Include Usage
 */
#include <ING/Rendering/API/Usage/Usage.h>



/**
 *	Include CPUAccessFlag
 */
#include <ING/Rendering/API/CPUAccessFlag/CPUAccessFlag.h>



/**
 *	Include MiscFlag
 */
#include <ING/Rendering/API/MiscFlag/MiscFlag.h>



/**
 *	Include Format
 */
#include <ING/Rendering/API/Format/Format.h>



namespace ING {

	namespace Rendering {

		struct IndexBufferDesc {

			size_t			count;
			Format			format;
			Usage			usage;
			BindFlag		bindFlags;
			CPUAccessFlag   cpuAccessFlags;

		};

	}

}
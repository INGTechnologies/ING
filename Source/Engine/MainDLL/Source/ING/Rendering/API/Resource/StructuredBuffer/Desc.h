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



namespace ING {

	namespace Rendering {

		struct StructuredBufferDesc {

			size_t			count;
			unsigned int	stride;
			Usage			usage;
			BindFlag		bindFlags;
			CPUAccessFlag   cpuAccessFlags;

		};

	}

}
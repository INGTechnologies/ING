#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Format
 */
#include <ING/Rendering/API/Format/Format.h>



/**
 *	Include BindFlag
 */
#include <ING/Rendering/API/BindFlag/BindFlag.h>



/**
 *	Include Desc
 */
#include "Desc.h"



namespace ING {

	namespace Rendering {

		class IDevice;

		class IBuffer;



		class ING_API IIndexBuffer
		{

		public:
			static IBuffer* Create(IDevice* device, unsigned int count, Format format, void* pData);

			static IBuffer* Create(IDevice* device, const IndexBufferDesc& desc, void* pData);

		};

	}

}
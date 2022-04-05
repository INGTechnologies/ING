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
 *	Include Resource
 */
#include <ING/Rendering/API/Resource/Resource.h>



/**
 *	Include Desc
 */
#include "Desc.h"



namespace ING {

	namespace Rendering {

		class IDevice;

		class IBuffer;



		class ING_API IStructuredBuffer
		{

			/**
			 *	Create Methods
			 */
		public:
			static IBuffer* Create(IDevice* device, size_t count, unsigned int stride, void* pData);
			static IBuffer* Create(size_t count, unsigned int stride, void* pData);

			static IBuffer* Create(IDevice* device, const StructuredBufferDesc& desc, void* pData);
			static IBuffer* Create(const StructuredBufferDesc& desc, void* pData);

		};

	}

}
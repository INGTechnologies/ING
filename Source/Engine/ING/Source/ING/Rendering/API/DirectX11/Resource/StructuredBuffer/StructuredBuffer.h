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
 *	Include BindFlag
 */
#include <ING/Rendering/API/BindFlag/BindFlag.h>



/**
 *	Include StructuredBufferDesc
 */
#include <ING/Rendering/API/Resource/StructuredBuffer/Desc.h>



namespace ING {

	namespace Rendering {

		class IDevice;

		class IBuffer;



		namespace DirectX11 {

			class ING_API StructuredBuffer
			{

			public:
				static IBuffer* Create(IDevice* device, unsigned int count, unsigned int stride, void* pData);

				static IBuffer* Create(IDevice* device, const StructuredBufferDesc& desc, void* pData);

			};

		}

	}

}
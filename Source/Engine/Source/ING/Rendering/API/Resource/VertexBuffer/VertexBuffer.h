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



namespace ING {

	namespace Rendering {

		class IDevice;

		class IBuffer;



		class ING_API IVertexBuffer
		{

		public:
			static IBuffer* Create(IDevice* device, unsigned int count, unsigned int stride, void* pData);

		};

	}

}
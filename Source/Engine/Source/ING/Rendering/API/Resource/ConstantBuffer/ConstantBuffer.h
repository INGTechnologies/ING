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



namespace ING {

	namespace Rendering {

		class IDevice;

		class IBuffer;



		class ING_API IConstantBuffer
		{

			/**
			 *	Create Methods
			 */
		public:
			static IBuffer* Create(IDevice* device, unsigned int size, void* pData);

		};

	}

}
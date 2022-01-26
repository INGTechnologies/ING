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

		enum APIFlag {

			NONE_API_FLAG,

			DIRECTX11_API_FLAG,

			DIRECTX12_API_FLAG,

			VULKAN_API_FLAG,

			OPENGL_API_FLAG

		};

	}

}
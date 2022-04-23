#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



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
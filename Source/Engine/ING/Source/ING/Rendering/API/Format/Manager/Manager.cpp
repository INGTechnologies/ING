
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Application Configuration
 */
#include <ING//Configuration/Configuration.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include API
 */
#include <ING\Rendering/API/API.h>



/**
 *	Include APIs
 */
#include <ING\Rendering/API/DirectX11/API.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		FormatManager::FormatManager() {

			Debug::Log("Start Creating Rendering::FormatManager");



			Debug::Log("Rendering::FormatManager Created");

		}

		FormatManager::~FormatManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool FormatManager::Init() {

			Debug::Log("Start Initializing Rendering::FormatManager");

			/* Create Format To Stride Map */
			//format2StrideMap[FORMAT_UNKNOWN] = 0;
			format2StrideMap[FORMAT_R32G32B32A32_TYPELESS] = 16;
			format2StrideMap[FORMAT_R32G32B32A32_FLOAT] = 16;
			format2StrideMap[FORMAT_R32G32B32A32_UINT] = 16;
			format2StrideMap[FORMAT_R32G32B32A32_SINT] = 16;
			format2StrideMap[FORMAT_R32G32B32_TYPELESS] = 12;
			format2StrideMap[FORMAT_R32G32B32_FLOAT] = 12;
			format2StrideMap[FORMAT_R32G32B32_UINT] = 12;
			format2StrideMap[FORMAT_R32G32B32_SINT] = 12;
			format2StrideMap[FORMAT_R16G16B16A16_TYPELESS] = 8;
			format2StrideMap[FORMAT_R16G16B16A16_FLOAT] = 8;
			format2StrideMap[FORMAT_R16G16B16A16_UNORM] = 8;
			format2StrideMap[FORMAT_R16G16B16A16_UINT] = 8;
			format2StrideMap[FORMAT_R16G16B16A16_SNORM] = 8;
			format2StrideMap[FORMAT_R16G16B16A16_SINT] = 8;
			format2StrideMap[FORMAT_R32G32_TYPELESS] = 8;
			format2StrideMap[FORMAT_R32G32_FLOAT] = 8;
			format2StrideMap[FORMAT_R32G32_UINT] = 8;
			format2StrideMap[FORMAT_R32G32_SINT] = 8;
			format2StrideMap[FORMAT_R32G8X24_TYPELESS] = 8;
			format2StrideMap[FORMAT_D32_FLOAT_S8X24_UINT] = 8;
			format2StrideMap[FORMAT_R32_FLOAT_X8X24_TYPELESS] = 8;
			format2StrideMap[FORMAT_X32_TYPELESS_G8X24_UINT] = 8;
			format2StrideMap[FORMAT_R10G10B10A2_TYPELESS] = 4;
			format2StrideMap[FORMAT_R10G10B10A2_UNORM] = 4;
			format2StrideMap[FORMAT_R10G10B10A2_UINT] = 4;
			format2StrideMap[FORMAT_R11G11B10_FLOAT] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_TYPELESS] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_UNORM] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_UNORM_SRGB] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_UINT] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_SNORM] = 4;
			format2StrideMap[FORMAT_R8G8B8A8_SINT] = 4;
			format2StrideMap[FORMAT_R16G16_TYPELESS] = 4;
			format2StrideMap[FORMAT_R16G16_FLOAT] = 4;
			format2StrideMap[FORMAT_R16G16_UNORM] = 4;
			format2StrideMap[FORMAT_R16G16_UINT] = 4;
			format2StrideMap[FORMAT_R16G16_SNORM] = 4;
			format2StrideMap[FORMAT_R16G16_SINT] = 4;
			format2StrideMap[FORMAT_R32_TYPELESS] = 4;
			format2StrideMap[FORMAT_D32_FLOAT] = 4;
			format2StrideMap[FORMAT_R32_FLOAT] = 4;
			format2StrideMap[FORMAT_R32_UINT] = 4;
			format2StrideMap[FORMAT_R32_SINT] = 4;
			format2StrideMap[FORMAT_R24G8_TYPELESS] = 4;
			format2StrideMap[FORMAT_D24_UNORM_S8_UINT] = 4;
			format2StrideMap[FORMAT_R24_UNORM_X8_TYPELESS] = 4;
			format2StrideMap[FORMAT_X24_TYPELESS_G8_UINT] = 4;
			format2StrideMap[FORMAT_R8G8_TYPELESS] = 2;
			format2StrideMap[FORMAT_R8G8_UNORM] = 2;
			format2StrideMap[FORMAT_R8G8_UINT] = 2;
			format2StrideMap[FORMAT_R8G8_SNORM] = 2;
			format2StrideMap[FORMAT_R8G8_SINT] = 2;
			format2StrideMap[FORMAT_R16_TYPELESS] = 2;
			format2StrideMap[FORMAT_R16_FLOAT] = 2;
			format2StrideMap[FORMAT_D16_UNORM] = 2;
			format2StrideMap[FORMAT_R16_UNORM] = 2;
			format2StrideMap[FORMAT_R16_UINT] = 2;
			format2StrideMap[FORMAT_R16_SNORM] = 2;
			format2StrideMap[FORMAT_R16_SINT] = 2;
			format2StrideMap[FORMAT_R8_TYPELESS] = 1;
			format2StrideMap[FORMAT_R8_UNORM] = 1;
			format2StrideMap[FORMAT_R8_UINT] = 1;
			format2StrideMap[FORMAT_R8_SNORM] = 1;
			format2StrideMap[FORMAT_R8_SINT] = 1;
			format2StrideMap[FORMAT_A8_UNORM] = 1;
			//format2StrideMap[FORMAT_R1_UNORM] = 0;
			format2StrideMap[FORMAT_R9G9B9E5_SHAREDEXP] = 4;
			format2StrideMap[FORMAT_R8G8_B8G8_UNORM] = 4;
			format2StrideMap[FORMAT_G8R8_G8B8_UNORM] = 4;
			//format2StrideMap[FORMAT_BC1_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC1_UNORM] = 0;
			//format2StrideMap[FORMAT_BC1_UNORM_SRGB] = 0;
			//format2StrideMap[FORMAT_BC2_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC2_UNORM] = 0;
			//format2StrideMap[FORMAT_BC2_UNORM_SRGB] = 0;
			//format2StrideMap[FORMAT_BC3_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC3_UNORM] = 0;
			//format2StrideMap[FORMAT_BC3_UNORM_SRGB] = 0;
			//format2StrideMap[FORMAT_BC4_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC4_UNORM] = 0;
			//format2StrideMap[FORMAT_BC4_SNORM] = 0;
			//format2StrideMap[FORMAT_BC5_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC5_UNORM] = 0;
			//format2StrideMap[FORMAT_BC5_SNORM] = 0;
			format2StrideMap[FORMAT_B5G6R5_UNORM] = 2;
			format2StrideMap[FORMAT_B5G5R5A1_UNORM] = 0;
			format2StrideMap[FORMAT_B8G8R8A8_UNORM] = 4;
			format2StrideMap[FORMAT_B8G8R8X8_UNORM] = 4;
			format2StrideMap[FORMAT_R10G10B10_XR_BIAS_A2_UNORM] = 4;
			format2StrideMap[FORMAT_B8G8R8A8_TYPELESS] = 4;
			format2StrideMap[FORMAT_B8G8R8A8_UNORM_SRGB] = 4;
			format2StrideMap[FORMAT_B8G8R8X8_TYPELESS] = 4;
			format2StrideMap[FORMAT_B8G8R8X8_UNORM_SRGB] = 4;
			//format2StrideMap[FORMAT_BC6H_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC6H_UF16] = 0;
			//format2StrideMap[FORMAT_BC6H_SF16] = 0;
			//format2StrideMap[FORMAT_BC7_TYPELESS] = 0;
			//format2StrideMap[FORMAT_BC7_UNORM] = 0;
			//format2StrideMap[FORMAT_BC7_UNORM_SRGB] = 0;
			format2StrideMap[FORMAT_AYUV] = 4;
			//format2StrideMap[FORMAT_Y410] = 0;
			//format2StrideMap[FORMAT_Y416] = 0;
			//format2StrideMap[FORMAT_NV12] = 0;
			//format2StrideMap[FORMAT_P010] = 0;
			//format2StrideMap[FORMAT_P016] = 0;
			//format2StrideMap[FORMAT_420_OPAQUE] = 0;
			//format2StrideMap[FORMAT_YUY2] = 0;
			//format2StrideMap[FORMAT_Y210] = 0;
			//format2StrideMap[FORMAT_Y216] = 0;
			//format2StrideMap[FORMAT_NV11] = 0;
			//format2StrideMap[FORMAT_AI44] = 0;
			//format2StrideMap[FORMAT_IA44] = 0;
			//format2StrideMap[FORMAT_P8] = 0;
			//format2StrideMap[FORMAT_A8P8] = 0;
			//format2StrideMap[FORMAT_B4G4R4A4_UNORM] = 2;
			//format2StrideMap[FORMAT_P208] = 0;
			//format2StrideMap[FORMAT_V208] = 0;
			//format2StrideMap[FORMAT_V408] = 0;
			//format2StrideMap[FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE] = DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE;
			//format2StrideMap[FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE] = DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE;
			//format2StrideMap[FORMAT_FORCE_UINT] = 0;

			Debug::Log("Rendering::FormatManager Initialized");

			return true;
		}

		bool FormatManager::Run() {

			Debug::Log("Start Running Rendering::FormatManager");

			return true;
		}

		bool FormatManager::Release() {

			Debug::Log("Start Releasing Rendering::FormatManager");

			delete this;

			Debug::Log("Finished Releasing Rendering::FormatManager");

			return true;

		}



		/**
		 *	Properties
		 */
		unsigned int FormatManager::GetStride(Format format) {

			return format2StrideMap[format];

		}

	}
}

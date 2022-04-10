
/**
 *	Include Header
 */
#include "StructuredBuffer.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include DirectX11 ConstantBuffer
 */
#include <ING/Rendering/API/DirectX11/Resource/StructuredBuffer/StructuredBuffer.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Create Methods
		 */
		IBuffer* IStructuredBuffer::Create(size_t count, unsigned int stride, void* pData) {

			return Create(

				IAPI::GetInstance()->GetDevice(),

				count,

				stride,

				pData

			);

		}

		IBuffer* IStructuredBuffer::Create(IDevice* device, size_t count, unsigned int stride, void* pData) {

			return Create(
			
				device,

				{

					count,
					
					stride,

					USAGE_DEFAULT,

					BIND_SHADER_RESOURCE,

					(CPUAccessFlag)0

				},
				
				pData
			
			);

		}

		IBuffer* IStructuredBuffer::Create(const StructuredBufferDesc& desc, void* pData) {

			return Create(
			
				IAPI::GetInstance()->GetDevice(),

				desc,

				pData
			
			);

		}

		IBuffer* IStructuredBuffer::Create(IDevice* device, const StructuredBufferDesc& desc, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::StructuredBuffer::Create(device, desc, pData);

				break;

			case DIRECTX12_API_FLAG:

				break;

			case VULKAN_API_FLAG:

				break;

			case OPENGL_API_FLAG:

				break;

			default:
				break;
			}

			return nullptr;
		}

	}

}

/**
 *	Include Header
 */
#include "IndexBuffer.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Index Buffer
 */
#include <ING/Rendering/API/DirectX11/Resource/IndexBuffer/IndexBuffer.h>



namespace ING {

	namespace Rendering {

		IBuffer* IIndexBuffer::Create(IDevice* device, unsigned int count, Format format, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::IndexBuffer::Create(device, count, format, pData);

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

		IBuffer* IIndexBuffer::Create(IDevice* device, const IndexBufferDesc& desc, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::IndexBuffer::Create(device, desc, pData);

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
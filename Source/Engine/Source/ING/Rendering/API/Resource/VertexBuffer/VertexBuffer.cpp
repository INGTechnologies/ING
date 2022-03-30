
/**
 *	Include Header
 */
#include "VertexBuffer.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Vertex Buffer
 */
#include <ING/Rendering/API/DirectX11/Resource/VertexBuffer/VertexBuffer.h>



namespace ING {

	namespace Rendering {

		IBuffer* IVertexBuffer::Create(IDevice* device, unsigned int count, unsigned int stride, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::VertexBuffer::Create(device, count, stride, pData);

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

		IBuffer* IVertexBuffer::Create(IDevice* device, const VertexBufferDesc& desc, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::VertexBuffer::Create(device, desc, pData);

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
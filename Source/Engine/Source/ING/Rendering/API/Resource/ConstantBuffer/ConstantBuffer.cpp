
/**
 *	Include Header
 */
#include "ConstantBuffer.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 ConstantBuffer
 */
#include <ING/Rendering/API/DirectX11/Resource/ConstantBuffer/ConstantBuffer.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Create Methods
		 */
		IBuffer* IConstantBuffer::Create(IDevice* device, unsigned int size, void* pData) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::ConstantBuffer::Create(device, size, pData);

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
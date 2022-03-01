
/**
 *	Include Header
 */
#include "Buffer.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Texture2D
 */
#include <ING/Rendering/API/DirectX11/Resource/Buffer/Buffer.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Buffer::Buffer(Rendering::Device* device) : Resource(device){



		}

		Buffer::~Buffer() {



		}



		/**
		 *	Create, Release Methods
		 */
		Buffer*	Buffer::Create(Rendering::Device* device) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::Buffer(device);

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

		void	Buffer::Release() {

			delete this;

		}

	}

}
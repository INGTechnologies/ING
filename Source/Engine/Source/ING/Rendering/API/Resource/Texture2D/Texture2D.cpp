
/**
 *	Include Header
 */
#include "Texture2D.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Texture2D
 */
#include <ING/Rendering/API/DirectX11/Resource/Texture2D/Texture2D.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		ITexture2D::ITexture2D	() {



		}

		ITexture2D::~ITexture2D	() {



		}



		/**
		 *	Create, Release Method
		 */
		ITexture2D* ITexture2D::Create() {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::Texture2D();

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

		void ITexture2D::Release() {

			delete this;

		}

	}

}

/**
 *	Include Header
 */
#include "Convertor.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IConvertor::IConvertor() {



		}

		IConvertor::~IConvertor() {



		}



		/**
		 *	Create, Release Methods
		 */
		IConvertor* IConvertor::Create() {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::Convertor();

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

		void IConvertor::Release() {

			delete this;

		}

	}

}
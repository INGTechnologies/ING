
/**
 *	Include Header
 */
#include "VertexShader.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include DirectX11 Vertex Shader
 */
#include <ING/Rendering/API/DirectX11/Shader/VertexShader/VertexShader.h>



/**
 *	Include File Resource
 */
#include <ING/Resource/File/File.h>



/**
 *	Include Resource Manager
 */
#include <ING/Resource/Manager/Manager.h>



#include <algorithm>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IVertexShader::IVertexShader(IDevice* device) : IShader("VertexShader") {

			this->device = device;

		}

		IVertexShader::~IVertexShader() {



		}



		/**
		 *	Create Methods
		 */
		IVertexShader* IVertexShader::CreateFromHLSL(IDevice* device, const std::wstring& filePath) {

			FileResource* fileResource = ResourceManager::GetInstance()->LoadResource<FileResource>(Path::GetAbsolutePath(filePath));

			std::string basicStrContent = ToString(fileResource->content);

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::VertexShader::CreateFromHLSL(device, basicStrContent);

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

		IVertexShader* IVertexShader::CreateFromHLSL(const std::wstring& filePath) {

			return CreateFromHLSL(IAPI::GetInstance()->GetDevice(), filePath);

		}



		/**
		 *	Methods
		 */
		void IVertexShader::Apply(const std::string& name) {



		}

	}

}
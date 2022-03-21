
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 DeviceContext
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDeviceContext::IDeviceContext(IDevice* device) {

			this->device = device;

		}

		IDeviceContext::~IDeviceContext() {



		}



		/**
		 *	Create, Release Methods
		 */
		IDeviceContext* IDeviceContext::Create(IDevice* device) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::DeviceContext(device);

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

		void IDeviceContext::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IDeviceContext::IASetInputLayout(IInputLayout* inputLayout) {



		}

		void IDeviceContext::IASetPrimitiveTopology(PrimitiveTopology primitiveTopology) {



		}

		void IDeviceContext::IASetVertexBuffers(const std::vector<IBuffer*>& buffers) {



		}

		void IDeviceContext::IASetVertexBuffer(IBuffer* buffer, unsigned int stride, unsigned int offset) {



		}

		void IDeviceContext::IASetIndexBuffer(IBuffer* buffer, Format format, unsigned int offset) {



		}

		void IDeviceContext::OMSetRenderTargets(const std::vector<IRenderTargetView*>& rtvs, IDepthStencilVIew* dsv) {



		}

		void IDeviceContext::OMSetRenderTargets(IRenderTargetView* rtv, IDepthStencilVIew* dsv) {



		}

		void IDeviceContext::VSSetShader(IVertexShader* vertexShader) {



		}

		void IDeviceContext::PSSetShader(IPixelShader* pixelShader) {



		}

		void IDeviceContext::DrawIndexed(unsigned int indexCount, unsigned int startIndexLocation, int baseVertexLocation) {



		}

	}

}
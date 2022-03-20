
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



/**
 *	Include DirectX11 Input Layout
 */
#include <ING/Rendering/API/DirectX11/InputLayout/InputLayout.h>



/**
 *	Include DirectX11 Buffer
 */
#include <ING/Rendering/API/DirectX11/Resource/Buffer/Buffer.h>



/**
 *	Include DirectX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			DeviceContext::DeviceContext(Rendering::IDevice* device):
				Rendering::IDeviceContext(device)
			{

				((DirectX11::Device*)device)->GetD3D11Device()->GetImmediateContext(&d3d11DeviceContext);

			}

			DeviceContext::~DeviceContext() {



			}



			/**
			 *	Release Methods
			 */
			void DeviceContext::Release() {

				if (d3d11DeviceContext != nullptr) {

					d3d11DeviceContext->Release();

				}

				IDeviceContext::Release();

			}



			/**
			 *	Methods
			 */
			void DeviceContext::IASetInputLayout(IInputLayout* inputLayout) {

				d3d11DeviceContext->IASetInputLayout(inputLayout->As<DirectX11::InputLayout>()->GetD3D11InputLayout());

			}

			void DeviceContext::IASetVertexBuffers(const std::vector<IBuffer*>& buffers) {



			}

			void DeviceContext::IASetVertexBuffer(IBuffer* buffer, unsigned int stride, unsigned int offset) {

				ID3D11Buffer* d3d11Buffer = buffer->As<DirectX11::Buffer>()->GetD3D11Buffer();

				d3d11DeviceContext->IASetVertexBuffers(0,1,&d3d11Buffer,&stride, &offset);

			}

			void DeviceContext::IASetIndexBuffer(IBuffer* buffer, Format format, unsigned int offset) {

				ID3D11Buffer* d3d11Buffer = buffer->As<DirectX11::Buffer>()->GetD3D11Buffer();

				d3d11DeviceContext->IASetIndexBuffer(d3d11Buffer, DirectX11::Convertor::GetInstance()->Format(format), offset);

			}

		}

	}

}
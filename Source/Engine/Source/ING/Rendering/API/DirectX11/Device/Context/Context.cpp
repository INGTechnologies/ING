
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



/**
 *	Include DirectX11 RenderTargetView
 */
#include <ING/Rendering/API/DirectX11/View/RenderTargetView/RenderTargetView.h>



/**
 *	Include DirectX11 VertexShader
 */
#include <ING/Rendering/API/DirectX11/Shader/VertexShader/VertexShader.h>



/**
 *	Include DirectX11 PixelShader
 */
#include <ING/Rendering/API/DirectX11/Shader/PixelShader/PixelShader.h>



/**
 *	Include DirectX11 Rasterizer State
 */
#include <ING/Rendering/API/DirectX11/State/RasterizerState/RasterizerState.h>



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

			void DeviceContext::IASetPrimitiveTopology(PrimitiveTopology primitiveTopology) {

				d3d11DeviceContext->IASetPrimitiveTopology(DirectX11::Convertor::GetInstance()->PrimitiveTopology(primitiveTopology));

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

			void DeviceContext::OMSetRenderTargets(const std::vector<IRenderTargetView*>& rtvs, IDepthStencilVIew* dsv) {



			}

			void DeviceContext::OMSetRenderTargets(IRenderTargetView* rtv, IDepthStencilVIew* dsv) {

				ID3D11RenderTargetView* d3d11RTV = rtv->As<DirectX11::RenderTargetView>()->GetD3D11RenderTargetView();

				if(dsv == 0)
					d3d11DeviceContext->OMSetRenderTargets(1, &d3d11RTV, 0);

			}

			void DeviceContext::RSSetState(IRasterizerState* state) {

				d3d11DeviceContext->RSSetState(state->As<DirectX11::RasterizerState>()->GetD3D11RSState());

			}

			void DeviceContext::VSSetShader(IVertexShader* vertexShader) {

				d3d11DeviceContext->VSSetShader(vertexShader->As<DirectX11::VertexShader>()->GetD3D11VertexShader(),0,0);

			}

			void DeviceContext::PSSetShader(IPixelShader* pixelShader) {

				d3d11DeviceContext->PSSetShader(pixelShader->As<DirectX11::PixelShader>()->GetD3D11PixelShader(), 0, 0);

			}

			void DeviceContext::PSSetConstantBuffers(const std::vector<IBuffer*>& cbuffers) {

				ID3D11Buffer** d3d11Buffers = (ID3D11Buffer**)malloc(sizeof(ID3D11Buffer*) * cbuffers.size());

				unsigned int count = cbuffers.size();

				for (unsigned int i = 0; i < count; ++i) {

					d3d11Buffers[i] = cbuffers[i]->As<DirectX11::Buffer>()->GetD3D11Buffer();

				}

				d3d11DeviceContext->PSSetConstantBuffers(0,count, d3d11Buffers);

				free(d3d11Buffers);

			}

			void DeviceContext::VSSetConstantBuffers(const std::vector<IBuffer*>& cbuffers) {

				ID3D11Buffer** d3d11Buffers = (ID3D11Buffer**)malloc(sizeof(ID3D11Buffer*) * cbuffers.size());

				unsigned int count = cbuffers.size();

				for (unsigned int i = 0; i < count; ++i) {

					d3d11Buffers[i] = cbuffers[i]->As<DirectX11::Buffer>()->GetD3D11Buffer();

				}

				d3d11DeviceContext->VSSetConstantBuffers(0, count, d3d11Buffers);

				free(d3d11Buffers);

			}

			void DeviceContext::DrawIndexed(unsigned int indexCount, unsigned int startIndexLocation, int baseVertexLocation) {

				d3d11DeviceContext->DrawIndexed(indexCount, startIndexLocation, baseVertexLocation);

			}

		}

	}

}
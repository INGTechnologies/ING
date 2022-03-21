
/**
 *	Include Header
 */
#include "SwapChain.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device Context
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include DirectX11 Texture2D
 */
#include <ING/Rendering/API/DirectX11/Resource/Texture2D/Texture2D.h>



/**
 *	Include DirectX11 RenderTargetView
 */
#include <ING/Rendering/API/DirectX11/View/RenderTargetView/RenderTargetView.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			SwapChain::SwapChain(IDevice* device, Window* window) :
				ISwapChain(device, window)
			{

				ID3D11Device* d3d11Device = ((DirectX11::Device*)device)->GetD3D11Device();

				IDXGIFactory* dxgiFactory = ((DirectX11::Device*)device)->GetDXGIFactory();



				UINT clientWidth = window->GetDesc().clientWidth;
				UINT clientHeight = window->GetDesc().clientHeight;
				HWND hwnd = window->GetHandle();



				/* Create DXGI SwapChain */
				DXGI_SWAP_CHAIN_DESC desc;
				ZeroMemory(&desc, sizeof(desc));
				desc.BufferCount = 1;
				desc.BufferDesc.Width = clientWidth;
				desc.BufferDesc.Height = clientHeight;
				desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				desc.BufferDesc.RefreshRate.Numerator = 60;
				desc.BufferDesc.RefreshRate.Denominator = 1;
				desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				desc.OutputWindow = hwnd;
				desc.SampleDesc.Count = 1;
				desc.SampleDesc.Quality = 0;
				desc.Windowed = TRUE;

				HRESULT hr = dxgiFactory->CreateSwapChain(d3d11Device, &desc, &dxgiSwapChain);


				/* Release Buffer */
				ID3D11Texture2D* d3d11buffer = nullptr;
				dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&d3d11buffer);

				d3d11buffer->Release();


				
				Resize(clientWidth, clientHeight);

			}

			SwapChain::~SwapChain() {



			}



			/**
			 *	Release Methods
			 */
			void SwapChain::Release() {

				if(dxgiSwapChain != nullptr)
					dxgiSwapChain->Release();

				ISwapChain::Release();

			}



			/**
			 *	Methods
			 */
			void SwapChain::Resize(unsigned int width, unsigned int height) {

				ID3D11Device* d3d11Device = ((DirectX11::Device*)GetDevice())->GetD3D11Device();
				ID3D11DeviceContext* d3d11DeviceContext = ((DirectX11::DeviceContext*)(GetDevice()->GetContext()))->GetD3D11DeviceContext();



				/**
				 *	Release Render Target View
				 */
				ID3D11RenderTargetView* d3d11RTV = ((DirectX11::RenderTargetView*)GetRenderTargetView())->GetD3D11RenderTargetView();

				if (d3d11RTV != nullptr) {

					d3d11RTV->Release();

				}



				unsigned int FrameCount = 1;



				dxgiSwapChain->ResizeBuffers(FrameCount, width, height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);



				ID3D11Texture2D* d3d11buffer = nullptr;
				dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&d3d11buffer);

				d3d11Device->CreateRenderTargetView(d3d11buffer, NULL, &d3d11RTV);

				d3d11buffer->Release();



				GetRenderTargetView()->As<DirectX11::RenderTargetView>()->SetD3D11RenderTargetView(d3d11RTV);



				/* Set Viewport */
				D3D11_VIEWPORT vp[1];
				vp[0].Width = width;
				vp[0].Height = height;
				vp[0].MinDepth = 0;
				vp[0].MaxDepth = 1;
				vp[0].TopLeftX = 0;
				vp[0].TopLeftY = 0;

				d3d11DeviceContext->RSSetViewports(1, vp);
			}

			void SwapChain::Present() {

				dxgiSwapChain->Present(0, 0);

			}

		}

	}

}

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
 *	Include Window
 */
#include <ING/Window/Window.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			SwapChain::SwapChain(Rendering::Device* device, Window* window) :
				Rendering::SwapChain(device, window)
			{

				ID3D11Device* d3d11Device = ((DirectX11::Device*)device)->GetD3D11Device();

				IDXGIFactory* dxgiFactory = ((DirectX11::Device*)device)->GetDXGIFactory();

				UINT clientWidth = window->GetDesc().clientWidth;
				UINT clientHeight = window->GetDesc().clientHeight;
				HWND hwnd = window->GetHandle();

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

				ID3D11Texture2D* buffer = NULL;
				hr = dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

				ID3D11RenderTargetView* d3d11RTV = nullptr;

				HRESULT hr2 = d3d11Device->CreateRenderTargetView(buffer, NULL, &d3d11RTV);

			}

			SwapChain::~SwapChain() {



			}



			/**
			 *	Release Methods
			 */
			void SwapChain::Release() {

				Rendering::SwapChain::Release();

			}

		}

	}

}
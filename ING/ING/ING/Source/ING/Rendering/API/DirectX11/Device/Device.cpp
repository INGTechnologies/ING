
/**
 *	Include Header
 */
#include "Device.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering Device
 */
#include <ING\Rendering\API\Device\Context/Context.h>



/**
 *	Include Rendering SwapChain
 */
#include <ING\Rendering\API\SwapChain\SwapChain.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			Device::Device() {

				/**
				 *	Create D3DDevice
				 */
				D3D_DRIVER_TYPE driver_types[] =
				{
					D3D_DRIVER_TYPE_HARDWARE,
					D3D_DRIVER_TYPE_WARP,
					D3D_DRIVER_TYPE_REFERENCE
				};
				UINT num_driver_types = ARRAYSIZE(driver_types);

				D3D_FEATURE_LEVEL feature_levels[] =
				{
					D3D_FEATURE_LEVEL_11_0
				};
				UINT num_feature_levels = ARRAYSIZE(feature_levels);

				HRESULT res = 0;

				ID3D11DeviceContext* d3d11DeviceContext;

				for (UINT driver_type_index = 0; driver_type_index < num_driver_types;)
				{
					res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
						num_feature_levels, D3D11_SDK_VERSION, &d3d11Device, &featureLevel, &d3d11DeviceContext);
					if (SUCCEEDED(res))
						break;
					++driver_type_index;
				}



				/**
				 *	Check If Failed
				 */
				if (FAILED(res))
				{
					Debug::Error("Cant Init Rendering Device!!!");
					return;
				}



				/**
				 *	Get DXGIAdapter, DXGIFactory, DXGI Device
				 */
				res = d3d11Device->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);



				/**
				 *	Check If Failed
				 */
				if (FAILED(res))
				{
					Debug::Error("Cant Init Rendering Device!!!");
					return;
				}



				res = dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);



				/**
				 *	Check If Failed
				 */
				if (FAILED(res))
				{
					Debug::Error("Cant Init Rendering Device!!!");
					return;
				}



				res = dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);



				/**
				 *	Check If Failed
				 */
				if (FAILED(res))
				{
					Debug::Error("Cant Init Rendering Device!!!");
					return;
				}



				/**
				 *	Create Context
				 */
				context = Rendering::DeviceContext::Create(this);



				/**
				 *	Create SwapChain
				 */
				swapChain = Rendering::SwapChain::Create(this);

			}

			Device::~Device() {



			}



			/**
			 *	Release Methods
			 */
			void Device::Release() {

				Rendering::Device::Release();

			}

		}

	}

}
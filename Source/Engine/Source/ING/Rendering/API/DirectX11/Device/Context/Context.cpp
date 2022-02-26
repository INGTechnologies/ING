
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



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			DeviceContext::DeviceContext(Rendering::Device* device):
				Rendering::DeviceContext(device)
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

				Rendering::DeviceContext::Release();

			}



			/**
			 *	Methods
			 */
			void DeviceContext::ClearRenderTargetView(RenderTargetView* rtv, Color color) {



			}

		}

	}

}

/**
 *	Include Header
 */
#include "Buffer.h"



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device Context
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



/**
 *	Include DirectX11 Buffer
 */
#include <ING/Rendering/API/DirectX11/Resource/Buffer/Buffer.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			Buffer::Buffer(IDevice* device) : IBuffer(device) {



			}

			Buffer::Buffer(IDevice* device, ID3D11Buffer* d3d11Buffer) : Buffer(device) {

				this->d3d11Buffer = d3d11Buffer;

			}

			Buffer::~Buffer() {



			}



			/**
			 *	Release Method
			 */
			void Buffer::Release() {

				if (d3d11Buffer != nullptr) {

					d3d11Buffer->Release();

				}

				IBuffer::Release();

			}



			/**
			 *	Methods
			 */
			void Buffer::UpdateData(void* pData) {

				ID3D11DeviceContext* context = GetDevice()->GetContext()->As<DirectX11::DeviceContext>()->GetD3D11DeviceContext();

				context->UpdateSubresource(d3d11Buffer, 0, 0, pData, 0, 0);

			}

		}

	}

}
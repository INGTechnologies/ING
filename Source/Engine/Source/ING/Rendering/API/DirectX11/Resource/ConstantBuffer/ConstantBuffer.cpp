
/**
 *	Include Header
 */
#include "ConstantBuffer.h"



#include <d3d11.h>



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
			 *	Create Methods
			 */
			IBuffer* ConstantBuffer::Create(IDevice* device, unsigned int size, void* pData) {

				D3D11_BUFFER_DESC desc;
				desc.ByteWidth = size;
				desc.Usage = D3D11_USAGE_DEFAULT;
				desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
				desc.CPUAccessFlags = 0;
				desc.MiscFlags = 0;
				desc.StructureByteStride = 0;


				D3D11_SUBRESOURCE_DATA init;
				init.pSysMem = pData;
				init.SysMemPitch = 0;
				init.SysMemSlicePitch;


				ID3D11Device* d3d11Device = device->As<DirectX11::Device>()->GetD3D11Device();

				ID3D11Buffer* d3d11Buffer;

				HRESULT hr;

				if(pData != 0)
					hr = d3d11Device->CreateBuffer(&desc, &init, &d3d11Buffer);
				else
					hr = d3d11Device->CreateBuffer(&desc, 0, &d3d11Buffer);


				return new DirectX11::Buffer(device, d3d11Buffer);

			}

		}

	}

}
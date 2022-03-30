
/**
 *	Include Header
 */
#include "VertexBuffer.h"



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
 *	Include DirectX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h>



/**
 *	Include DirectX11 Buffer
 */
#include <ING/Rendering/API/DirectX11/Resource/Buffer/Buffer.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			IBuffer* VertexBuffer::Create(IDevice* device, unsigned int count, unsigned int stride, void* pData) {

				D3D11_BUFFER_DESC desc;
				desc.ByteWidth = count * stride;
				desc.Usage = D3D11_USAGE_DEFAULT;
				desc.BindFlags = BIND_VERTEX_BUFFER;
				desc.CPUAccessFlags = 0;
				desc.MiscFlags = 0;
				desc.StructureByteStride = 0;


				D3D11_SUBRESOURCE_DATA init;
				init.pSysMem = pData;
				init.SysMemPitch = 0;
				init.SysMemSlicePitch;


				ID3D11Device* d3d11Device = device->As<DirectX11::Device>()->GetD3D11Device();

				ID3D11Buffer* d3d11Buffer;

				HRESULT hr = d3d11Device->CreateBuffer(&desc, &init, &d3d11Buffer);

				return new DirectX11::Buffer(device, d3d11Buffer);

			}

			IBuffer* VertexBuffer::Create(IDevice* device, const VertexBufferDesc& vdesc, void* pData) {

				D3D11_BUFFER_DESC desc;
				desc.ByteWidth = vdesc.count * vdesc.stride;
				desc.Usage = DirectX11::Convertor::GetInstance()->Usage(vdesc.usage);
				desc.BindFlags = DirectX11::Convertor::GetInstance()->BindFlag(vdesc.bindFlags);
				desc.CPUAccessFlags = DirectX11::Convertor::GetInstance()->CPUAccessFlag(vdesc.cpuAccessFlags);
				desc.MiscFlags = 0;
				desc.StructureByteStride = 0;


				D3D11_SUBRESOURCE_DATA init;
				init.pSysMem = pData;
				init.SysMemPitch = 0;
				init.SysMemSlicePitch;


				ID3D11Device* d3d11Device = device->As<DirectX11::Device>()->GetD3D11Device();

				ID3D11Buffer* d3d11Buffer;

				HRESULT hr = d3d11Device->CreateBuffer(&desc, &init, &d3d11Buffer);

				return new DirectX11::Buffer(device, d3d11Buffer);

			}

		}

	}

}
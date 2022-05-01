
/**
 *	Include Header
 */
#include "VertexShader.h"



/**
 *	Include Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



/**
 *	Include Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			VertexShader::VertexShader(IDevice* device, ID3DBlob* blob) : 
				IVertexShader(device),

				blob(0),
				d3d11VertexShader(0) 
			{

				this->blob = blob;

				HRESULT hr = device->As<DirectX11::Device>()->GetD3D11Device()->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), 0, &d3d11VertexShader);

			}

			VertexShader::~VertexShader() {



			}



			/**
			 *	Create Methods
			 */
			VertexShader* VertexShader::CreateFromHLSL(IDevice* device, const String& content) {

				ID3DBlob* sBlob;
				ID3DBlob* errBlob;

				HRESULT hr = D3DCompile(content.c_str(), content.length(), 0, 0, 0, "main", "vs_5_0", D3DCOMPILE_ENABLE_STRICTNESS, 0, &sBlob, &errBlob);

				if (errBlob != 0) {
					MessageBoxA(0, (char*)errBlob->GetBufferPointer(), 0, 0);
				}

				if (FAILED(hr)) {
					return nullptr;
				}

				return new VertexShader(device, sBlob);
			}



			/**
			 *	Methods
			 */
			void VertexShader::Apply(const String& name) {

				IDeviceContext* context = GetDevice()->GetImmediateContext();

				context->VSSetShader(this);

			}

		}

	}

}
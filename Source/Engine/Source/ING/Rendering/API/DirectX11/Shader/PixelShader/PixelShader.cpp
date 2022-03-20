
/**
 *	Include Header
 */
#include "PixelShader.h"



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			PixelShader::PixelShader(IDevice* device, ID3DBlob* blob) : IPixelShader(device) {

				this->blob = blob;

			}

			PixelShader::~PixelShader() {



			}



			/**
			 *	Create Methods
			 */
			PixelShader* PixelShader::CreateFromHLSL(IDevice* device, const std::string& content) {

				ID3DBlob* sBlob;
				ID3DBlob* errBlob;

				HRESULT hr = D3DCompile(content.c_str(), content.length(), 0, 0, 0, "main", "ps_5_0", D3DCOMPILE_ENABLE_STRICTNESS, 0, &sBlob, &errBlob);

				if (errBlob != 0) {
					MessageBoxA(0, (char*)errBlob->GetBufferPointer(), 0, 0);
				}

				if (FAILED(hr)) {
					return nullptr;
				}

				return new PixelShader(device, sBlob);
			}

		}

	}

}
#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Pixel Shader
 */
#include <ING/Rendering/API/Shader/PixelShader/PixelShader.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



/**
 *	Include D3DCompiler
 */
#include <d3dcompiler.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API PixelShader : public IPixelShader {

				/**
				 *	Constructors And Destructor
				 */
			public:
				PixelShader(IDevice* device, ID3DBlob* blob);
				~PixelShader();



				/**
				 *	Create Methods
				 */
			public:
				static PixelShader* CreateFromHLSL(IDevice* device, const std::string& content);



				/**
				 *	Properties
				 */
			private:
				ID3DBlob* blob;
				ID3D11PixelShader* d3d11PixelShader;

			public:
				ID3DBlob* GetBlob() { return blob; }
				ID3D11PixelShader* GetD3D11PixelShader () { return d3d11PixelShader; }



				/**
				 *	Methods
				 */
			public:
				virtual void Apply(const std::string& name) override;

			};

		}

	}

}
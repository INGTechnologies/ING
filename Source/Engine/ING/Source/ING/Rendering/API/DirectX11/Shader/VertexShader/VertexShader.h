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
 *	Include Vertex Shader
 */
#include <ING/Rendering/API/Shader/VertexShader/VertexShader.h>



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

			class ING_API VertexShader : public IVertexShader {

				/**
				 *	Constructors And Destructor
				 */
			public:
				VertexShader(IDevice* device, ID3DBlob* blob);
				~VertexShader();



				/**
				 *	Create Methods
				 */
			public:
				static VertexShader* CreateFromHLSL(IDevice* device, const std::string& content);



				/**
				 *	Properties
				 */
				ID3DBlob* blob;
				ID3D11VertexShader* d3d11VertexShader;

			public:
				ID3DBlob* GetBlob() { return blob; }
				ID3D11VertexShader* GetD3D11VertexShader() { return d3d11VertexShader; }



				/**
				 *	Methods
				 */
			public:
				virtual void Apply(const std::string& name) override;

			};

		}

	}

}
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
 *	Include InputLayout
 */
#include <ING/Rendering/API/InputLayout/InputLayout.h>



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

			class ING_API InputLayout : public IInputLayout {

				/**
				 *	Constructors And Destructor
				 */
			public:
				InputLayout(IDevice* device, const std::vector<InputLayoutElementDesc>& desc, IVertexShader* vshader);
				~InputLayout();



				/**
				 *	Properties
				 */
			private:
				ID3D11InputLayout*	d3d11InputLayout;

			public:
				ID3D11InputLayout*	GetD3D11InputLayout() { return d3d11InputLayout; }
				void				SetD3D11InputLayout(ID3D11InputLayout* inputLayout) { this->d3d11InputLayout = d3d11InputLayout; }



				/**
				 *	Methods
				 */
			public:
				virtual void Apply() override;

			};

		}

	}

}
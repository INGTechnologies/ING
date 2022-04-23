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
 *	Include Rasterizer State
 */
#include <ING/Rendering/API/State/RasterizerState/RasterizerState.h>



#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API RasterizerState : public IRasterizerState {

				/**
				 *	Constructors And Destructor
				 */
			public:
				RasterizerState(IDevice* device, const std::string& name, const RasterizerStateDesc& desc);
				RasterizerState(const std::string& name, const RasterizerStateDesc& desc);
				~RasterizerState();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			public:
				ID3D11RasterizerState* d3d11RSState;

			public:
				ID3D11RasterizerState* GetD3D11RSState() { return d3d11RSState; }

			};

		}

	}

}
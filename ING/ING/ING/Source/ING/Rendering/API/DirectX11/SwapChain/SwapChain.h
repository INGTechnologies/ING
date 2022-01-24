#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering SwapChain
 */
#include <ING\Rendering\API\SwapChain\SwapChain.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API SwapChain : public Rendering::SwapChain
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				SwapChain(Rendering::Device* device);
				~SwapChain();



				/**
				 *	Release Methods
				 */
			public:
				virtual void	Release() override;



				/**
				 *	Properties
				 */
			private:
				IDXGISwapChain* dxgiSwapChain;

			public:
				IDXGISwapChain* GetDXGISwapChain() { return dxgiSwapChain; }

			};

		}

	}

}
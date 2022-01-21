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
 *	Include Rendering Device
 */
#include <ING\Rendering\API\Device\Device.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API Device : public Rendering::Device
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Device();
				~Device();



				/**
				 *	Release Methods
				 */
			public:
				virtual void	Release() override;



				/**
				 *	Properties
				 */
			private:
				ID3D11Device* d3d11Device;

				D3D_FEATURE_LEVEL featureLevel;

				IDXGIDevice* dxgiDevice;
				IDXGIAdapter* dxgiAdapter;
				IDXGIFactory* dxgiFactory;

			public:
				ID3D11Device*		GetD3D11Device()		{ return d3d11Device; }

				D3D_FEATURE_LEVEL	GetD3DFeatureLevel()	{ return featureLevel; }

				IDXGIDevice*		GetDXGIDevice()			{ return dxgiDevice; }

				IDXGIAdapter*		GetDXGIAdapter()		{ return dxgiAdapter; }

				IDXGIFactory*		GetDXGIFactory()		{ return dxgiFactory; }

			};

		}

	}

}
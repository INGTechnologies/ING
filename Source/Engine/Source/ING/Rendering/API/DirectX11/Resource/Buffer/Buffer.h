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
 *	Include Rendering Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API Buffer : public IBuffer
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Buffer(IDevice* device);
				~Buffer();



				/**
				 *	Create, Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	D3D11Buffer
				 */
			private:
				ID3D11Buffer*	d3d11Buffer;

			public:
				ID3D11Buffer*	GetD3D11Buffer	() { return d3d11Buffer; }

				void			SetD3D11Buffer	(ID3D11Buffer* d3d11Buffer) {

					this->d3d11Buffer = d3d11Buffer;

				}

			};

		}

	}

}
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
 *	Include Rendering Texture2D
 */
#include <ING/Rendering/API/Resource/Texture2D/Texture2D.h>



 /**
  *	Include D3D11
  */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API Texture2D : public ITexture2D
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Texture2D	(IDevice* device);
				~Texture2D	();



				/**
				 *	Create, Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	D3D11Texture2D
				 */
			private:
				ID3D11Texture2D* d3d11Texture2D;

			public:
				ID3D11Texture2D* GetD3D11Texture2D	() { return d3d11Texture2D; }

				void			 SetD3D11Texture2D	(ID3D11Texture2D* d3d11Texture2D) {

					this->d3d11Texture2D = d3d11Texture2D;

				}

			};

		}

	}

}
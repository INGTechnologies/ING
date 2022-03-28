
/**
 *	Include Header
 */
#include "Texture2D.h"



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			Texture2D::Texture2D(IDevice* device) : 
				ITexture2D(device), 
				
				d3d11Texture2D(0) 
			{



			}

			Texture2D::~Texture2D() {



			}



			/**
			 *	Release Method
			 */
			void Texture2D::Release() {

				Rendering::ITexture2D::Release();

			}

		}

	}

}
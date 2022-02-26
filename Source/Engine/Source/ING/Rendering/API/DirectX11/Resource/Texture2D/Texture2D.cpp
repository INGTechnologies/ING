
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
			Texture2D::Texture2D(Rendering::Device* device) : Rendering::Texture2D(device) {



			}

			Texture2D::~Texture2D() {



			}



			/**
			 *	Release Method
			 */
			void Texture2D::Release() {

				Rendering::Texture2D::Release();

			}

		}

	}

}
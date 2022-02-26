
/**
 *	Include Header
 */
#include "Buffer.h"



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			Buffer::Buffer(Rendering::Device* device) : Rendering::Buffer(device) {



			}

			Buffer::~Buffer() {



			}



			/**
			 *	Release Method
			 */
			void Buffer::Release() {

				Rendering::Buffer::Release();

			}

		}

	}

}
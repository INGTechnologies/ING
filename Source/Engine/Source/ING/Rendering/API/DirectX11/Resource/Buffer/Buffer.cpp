
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
			Buffer::Buffer(IDevice* device) : IBuffer(device) {



			}

			Buffer::Buffer(IDevice* device, ID3D11Buffer* d3d11Buffer) : Buffer(device) {

				this->d3d11Buffer = d3d11Buffer;

			}

			Buffer::~Buffer() {



			}



			/**
			 *	Release Method
			 */
			void Buffer::Release() {

				IBuffer::Release();

			}

		}

	}

}
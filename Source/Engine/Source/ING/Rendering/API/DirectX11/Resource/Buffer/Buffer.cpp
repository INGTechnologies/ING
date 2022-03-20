
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
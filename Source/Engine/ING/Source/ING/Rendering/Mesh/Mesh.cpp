
/**
 * Include Header
 */
#include "Mesh.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IMesh::IMesh() : IMesh(APIManager::GetInstance()->GetAPI()->GetDevice()) {



		}

		IMesh::IMesh(IDevice* device) :
			device(0),
			vertexBuffer(0),
			indexBuffer(0)
		{

			this->device = device;

			vertexBufferDesc = {

				0,
				0,
				USAGE_DEFAULT,
				BIND_VERTEX_BUFFER,
				(CPUAccessFlag)0

			};

			indexBufferDesc = {

				0,
				FORMAT_R32_UINT,
				USAGE_DEFAULT,
				BIND_VERTEX_BUFFER,
				(CPUAccessFlag)0

			};

		}

		IMesh::~IMesh() {



		}



		/**
		 *	Release Methods
		 */
		void IMesh::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IMesh::BuildBuffers() {



		}

	}

}
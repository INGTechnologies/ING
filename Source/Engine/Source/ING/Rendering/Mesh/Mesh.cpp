
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

		IMesh::IMesh(IDevice* device) {

			this->device = device;

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
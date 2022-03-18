
/**
 * Include Header
 */
#include "Mesh.h"




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IMesh::IMesh() {



		}

		IMesh::~IMesh() {



		}



		/**
		 *	Release Methods
		 */
		void IMesh::Release() {

			delete this;

		}

	}

}
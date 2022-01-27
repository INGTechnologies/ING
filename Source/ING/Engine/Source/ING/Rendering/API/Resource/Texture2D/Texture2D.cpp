
/**
 *	Include Header
 */
#include "Texture2D.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Texture2D::Texture2D() {



		}

		Texture2D::~Texture2D() {



		}



		/**
		 *	Release Method
		 */
		void Texture2D::Release() {

			delete this;

		}

	}

}
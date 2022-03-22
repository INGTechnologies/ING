#pragma once

/**
 *	Include AMath Types
 */
#include "../Types.h"



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constructors And Destructor
		 */
		Vector3::Vector3(const Math::Vector3& m) {

			memcpy(this, &m, 16);

		}



		/**
		 *	Methods
		 */
		CVector3 Vector3::Transpose() const {

			return m128;

		}

	}

}
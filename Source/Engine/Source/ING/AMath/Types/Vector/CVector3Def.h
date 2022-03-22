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
		CVector3::CVector3(const Math::CVector3& m) {

			memcpy(this, &m, 16);

		}



		/**
		 *	Methods
		 */
		Vector3	CVector3::Transpose() const {

			return m128;

		}

	}

}
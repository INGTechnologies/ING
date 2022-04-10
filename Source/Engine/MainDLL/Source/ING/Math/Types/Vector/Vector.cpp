
/**
 *	Include Math
 */
#include <ING/Math/Math.h>



namespace ING {

	namespace Math {

#pragma region CVector2
		/**
		 *	Methods
		 */
		RVector2	CVector2::Transpose() const {

			return *((RVector2*)this);

		}
#pragma endregion

#pragma region CVector3
		/**
		 *	Methods
		 */
		RVector3	CVector3::Transpose() const {

			return m128;

		}
#pragma endregion

#pragma region CVector4
		/**
			*	Methods
			*/
		RVector4	CVector4::Transpose() const {

			return m128;

		}
#pragma endregion



#pragma region RVector2
		/**
		 *	Methods
		 */
		CVector2	RVector2::Transpose() const {

			return *((CVector2*)this);

		}
#pragma endregion

#pragma region RVector3
		/**
		 *	Methods
		 */
		CVector3	RVector3::Transpose() const {

			return m128;

		}
#pragma endregion

#pragma region RVector4
		/**
		 *	Methods
		 */
		CVector4	RVector4::Transpose() const {

			return m128;

		}
#pragma endregion

	}

}
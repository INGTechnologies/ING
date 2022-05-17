#pragma once



/**
 *	Include Types
 */
#include "../../Types/Types.h"



/**
 *	Float To Matrix Functions
 */
namespace ING {

	namespace Math {

#ifdef NON_SIMD

		static inline RMatrix2x2 Matrix(RFloat2x2& f) {

			return *((RMatrix2x2*)&f);

		}
		static inline RMatrix2x3 Matrix(RFloat2x3& f) {

			RMatrix2x3 result;

			memcpy(&result, &f, 3 * sizeof(float));

			memcpy(((float*)&result) + 4, ((float*)&f) + 3, 3 * sizeof(float));

			return result;

		}
		static inline RMatrix2x4 Matrix(RFloat2x4& f) {

			return *((RMatrix2x4*)&f);

		}



		static inline RMatrix3x2 Matrix(RFloat3x2& f) {

			return *((RMatrix3x2*)&f);

		}
		static inline RMatrix3x3 Matrix(RFloat3x3& f) {

			RMatrix3x3 result;

			memcpy(&result, &f, 3 * sizeof(float));

			memcpy(((float*)&result) + 4, ((float*)&f) + 3, 3 * sizeof(float));

			memcpy(((float*)&result) + 8, ((float*)&f) + 6, 3 * sizeof(float));

			return result;

		}
		static inline RMatrix3x4 Matrix(RFloat3x4& f) {

			return *((RMatrix3x4*)&f);

		}



		static inline RMatrix4x2 Matrix(RFloat4x2& f) {

			return *((RMatrix4x2*)&f);

		}
		static inline RMatrix4x3 Matrix(RFloat4x3& f) {

			RMatrix4x3 result;

			memcpy(&result, &f, 3 * sizeof(float));

			memcpy(((float*)&result) + 4, ((float*)&f) + 3, 3 * sizeof(float));

			memcpy(((float*)&result) + 8, ((float*)&f) + 6, 3 * sizeof(float));

			memcpy(((float*)&result) + 12, ((float*)&f) + 9, 3 * sizeof(float));

			return result;

		}
		static inline RMatrix4x4 Matrix(RFloat4x4& f) {

			return *((RMatrix4x4*)&f);

		}

#endif

	}

}



/**
 *	Float To Vector Functions
 */
namespace ING {

	namespace Math {

#ifdef NON_SIMD

		static inline CVector2 Vector(const CFloat2& f) {

			return *((CVector2*)&f);

		}
		static inline CVector3 Vector(const CFloat3& f) {

			return *((CVector3*)&f);

		}
		static inline CVector4 Vector(const CFloat4& f) {

			return *((CVector4*)&f);

		}



		static inline RVector2 Vector(const RFloat2& f) {

			return *((RVector2*)&f);

		}
		static inline RVector3 Vector(const RFloat3& f) {

			return *((RVector3*)&f);

		}
		static inline RVector4 Vector(const RFloat4& f) {

			return *((RVector4*)&f);

		}

#endif

	}

}



/**
 *	Matrix, Vector To Float Functions
 */
namespace ING {

	namespace Math {

#ifdef NON_SIMD

		static inline CFloat2 Float(CVector2& f) {

			return *((CFloat2*)&f);

		}
		static inline CFloat3 Float(CVector3& f) {

			return *((CFloat3*)&f);

		}
		static inline CFloat4 Float(CVector4& f) {

			return *((CFloat4*)&f);

		}



		static inline RFloat2 Float(RVector2& f) {

			return *((RFloat2*)&f);

		}
		static inline RFloat3 Float(RVector3& f) {

			return *((RFloat3*)&f);

		}
		static inline RFloat4 Float(RVector4& f) {

			return *((RFloat4*)&f);

		}



		static inline RFloat2x2 Float(RMatrix2x2& f) {

			return *((RFloat2x2*)&f);

		}
		static inline RFloat2x3 Float(RMatrix2x3& f) {

			void* result = malloc(sizeof(float) * 6);

			memcpy(result, &f, 3 * sizeof(float));

			memcpy(((float*)result) + 3, ((float*)&f) + 4, 3 * sizeof(float));

			return *((RFloat2x3*)result);

		}
		static inline RFloat2x4 Float(RMatrix2x4& f) {

			return *((RFloat2x4*)&f);

		}



		static inline RFloat3x2 Float(RMatrix3x2& f) {

			return *((RFloat3x2*)&f);

		}
		static inline RFloat3x3 Float(RMatrix3x3& f) {

			void* result = malloc(sizeof(float) * 9);

			memcpy(result, &f, 3 * sizeof(float));

			memcpy(((float*)result) + 3, ((float*)&f) + 4, 3 * sizeof(float));

			memcpy(((float*)result) + 6, ((float*)&f) + 8, 3 * sizeof(float));

			return *((RFloat3x3*)result);

		}
		static inline RFloat3x4 Float(RMatrix3x4& f) {

			return *((RFloat3x4*)&f);

		}



		static inline RFloat4x2 Float(RMatrix4x2& f) {

			return *((RFloat4x2*)&f);

		}
		static inline RFloat4x3 Float(RMatrix4x3& f) {

			void* result = malloc(sizeof(float) * 12);

			memcpy(result, &f, 3 * sizeof(float));

			memcpy(((float*)result) + 3, ((float*)&f) + 4, 3 * sizeof(float));

			memcpy(((float*)result) + 6, ((float*)&f) + 8, 3 * sizeof(float));

			memcpy(((float*)result) + 9, ((float*)&f) + 12, 3 * sizeof(float));

			return *((RFloat4x3*)result);

		}
		static inline RFloat4x4 Float(RMatrix4x4& f) {

			return *((RFloat4x4*)&f);

		}

#endif

	}

}
#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



#include "../TypeDeclares.h"



namespace ING {

	namespace Math {

#pragma region CFloat2
		struct ING_API CFloat2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2(float _x, float _y) {
				x = _x;
				y = _y;
			}

			inline CFloat2() :
				CFloat2((void*)&m128_0_0_0_0)
			{

			}

			inline CFloat2(const CFloat2& m) {

				memcpy(this, &m, sizeof(CFloat2));

			}

			inline CFloat2(void* m) {

				memcpy(this, m, sizeof(CFloat2));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion
		
#pragma region CFloat3
		struct ING_API CFloat3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3(float _x, float _y, float _z) {
				x = _x;
				y = _y;
				z = _z;
			}

			inline CFloat3() :
				CFloat3((void*)&m128_0_0_0_0)
			{

			}

			inline CFloat3(const CFloat3& m) {

				memcpy(this, &m, sizeof(CFloat3));

			}

			inline CFloat3(void* m) {

				memcpy(this, m, sizeof(CFloat3));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion
		
#pragma region CFloat4
		struct ING_API CFloat4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			inline CFloat4(__m128 m) : m128(m) {}

			inline CFloat4() :
				CFloat4(m128_0_0_0_0)
			{

			}

			inline CFloat4(const CFloat4& m) {

				memcpy(this, &m, sizeof(CFloat4));

			}

			inline CFloat4(void* m) {

				memcpy(this, m, sizeof(CFloat4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128 m128;

				struct {

					float x;
					float y;
					float z;
					float w;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion



#pragma region RFloat2
		struct ING_API RFloat2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2(float _x, float _y) {
				x = _x;
				y = _y;
			}

			inline RFloat2() :
				RFloat2((void*)&m128_0_0_0_0)
			{

			}

			inline RFloat2(const RFloat2& m) {

				memcpy(this, &m, sizeof(RFloat2));

			}

			inline RFloat2(void* m) {

				memcpy(this, m, sizeof(RFloat2));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion
		
#pragma region RFloat3
		struct ING_API RFloat3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3(float _x, float _y, float _z) {
				x = _x;
				y = _y;
				z = _z;
			}

			inline RFloat3() :
				RFloat3((void*)&m128_0_0_0_0)
			{

			}

			inline RFloat3(const RFloat3& m) {

				memcpy(this, &m, sizeof(RFloat3));

			}

			inline RFloat3(void* m) {

				memcpy(this, m, sizeof(RFloat3));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion
		
#pragma region RFloat4
		struct ING_API RFloat4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			inline RFloat4() :
				RFloat4((void*)&m128_0_0_0_0)
			{

			}

			inline RFloat4(const RFloat4& m) {

				memcpy(this, &m, sizeof(RFloat4));

			}

			inline RFloat4(void* m) {

				memcpy(this, m, sizeof(RFloat4));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;
			float w;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion



#pragma region RFloat4x4
		struct ING_API RFloat4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34,
				float _41, float _42, float _43, float _44
			) :
				m256_1(
					_mm256_set_ps(_24, _23, _22, _21, _14, _13, _12, _11)
				), 
				m256_2(
					_mm256_set_ps(_44, _43, _42, _41, _34, _33, _32, _31)
				)
			{}

			inline RFloat4x4(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline RFloat4x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RFloat4x4() :
				RFloat4x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RFloat4x4(const RFloat4x4& m) {

				memcpy(this, &m, sizeof(RFloat4x4));

			}

			inline RFloat4x4(void* m) {

				memcpy(this, m, sizeof(RFloat4x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m256 m256_1;
					__m256 m256_2;

				};

				struct {

					__m128 m128_1;
					__m128 m128_2;
					__m128 m128_3;
					__m128 m128_4;

				};

				struct {

					float _11; float _12; float _13; float _14;
					float _21; float _22; float _23; float _24;
					float _31; float _32; float _33; float _34;
					float _41; float _42; float _43; float _44;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
			}

			inline void		operator=(const RFloat4x4& m) {

				memcpy(this, &m, sizeof(RFloat4x4));

			}

		};
#pragma endregion



#pragma region FloatConvertors
		static inline CFloat2& Float(CVector2& f) {

			return *((CFloat2*)&f);

		}
		static inline CFloat3& Float(CVector3& f) {

			return *((CFloat3*)&f);

		}
		static inline CFloat4& Float(CVector4& f) {

			return *((CFloat4*)&f);

		}



		static inline RFloat2& Float(RVector2& f) {

			return *((RFloat2*)&f);

		}
		static inline RFloat3& Float(RVector3& f) {

			return *((RFloat3*)&f);

		}
		static inline RFloat4& Float(RVector4& f) {

			return *((RFloat4*)&f);

		}
#pragma endregion

	}

}
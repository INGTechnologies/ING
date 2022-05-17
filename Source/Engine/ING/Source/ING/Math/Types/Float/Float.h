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



namespace {

	static const float zeroMemoryForFloat[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
	static void* vZeroMemoryForFloat = (float*)zeroMemoryForFloat;

}



namespace ING {

	namespace Math {

#ifdef __AVX__

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

		
		


#pragma region CFloat2x2
		struct ING_API CFloat2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x2(
				float _11, float _12,
				float _21, float _22
			) :
				m128(
					_mm_set_ps(_22, _12, _21, _11)
				)
			{}

			inline CFloat2x2(__m128 m) : m128(m) {}

			inline CFloat2x2() :
				CFloat2x2(m128_0_0_0_0)
			{}

			inline CFloat2x2(const CFloat2x2& m) {

				memcpy(this, &m, sizeof(CFloat2x2));

			}

			inline CFloat2x2(void* m) {

				memcpy(this, m, sizeof(CFloat2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128 m128;

				struct {

					float _11; float _21;
					float _12; float _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x2& m) {

				memcpy(this, &m, sizeof(CFloat2x2));

			}

		};
#pragma endregion

#pragma region CFloat2x3
		struct ING_API CFloat2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline CFloat2x3() :
				CFloat2x3((void*)&m256_0_0_0_0_0_0_0_0)
			{}

			inline CFloat2x3(const CFloat2x3& m) {

				memcpy(this, &m, sizeof(CFloat2x3));

			}

			inline CFloat2x3(void* m) {

				memcpy(this, m, sizeof(CFloat2x3));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21;
			float _12; float _22; 
			float _13; float _23;



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x3& m) {

				memcpy(this, &m, sizeof(CFloat2x3));

			}

		};
#pragma endregion

#pragma region CFloat2x4
		struct ING_API CFloat2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				m256(
					_mm256_set_ps(_24, _14, _23, _13, _22, _12, _21, _11)
				)
			{}

			inline CFloat2x4(__m256 m) : m256(m) {}
			inline CFloat2x4(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline CFloat2x4() :
				CFloat2x4(m256_0_0_0_0_0_0_0_0)
			{}

			inline CFloat2x4(const CFloat2x4& m) {

				memcpy(this, &m, sizeof(CFloat2x4));

			}

			inline CFloat2x4(void* m) {

				memcpy(this, m, sizeof(CFloat2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256 m256;

				struct {

					__m128 m128_1;
					__m128 m128_2;

				};

				struct {

					float _11; float _21;
					float _12; float _22;
					float _13; float _23;
					float _14; float _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x4& m) {

				memcpy(this, &m, sizeof(CFloat2x4));

			}

		};
#pragma endregion

#pragma region CFloat3x2
		struct ING_API CFloat3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline CFloat3x2() :
				CFloat3x2((void*)&m256_0_0_0_0_0_0_0_0)
			{}

			inline CFloat3x2(const CFloat3x2& m) {

				memcpy(this, &m, sizeof(CFloat3x2));

			}

			inline CFloat3x2(void* m) {

				memcpy(this, m, sizeof(CFloat3x2));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21; float _31; 
			float _12; float _22; float _32;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x2& m) {

				memcpy(this, &m, sizeof(CFloat3x2));

			}

		};
#pragma endregion

#pragma region CFloat3x3
		struct ING_API CFloat3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline CFloat3x3() :
				CFloat3x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline CFloat3x3(const CFloat3x3& m) {

				memcpy(this, &m, sizeof(CFloat3x3));

			}

			inline CFloat3x3(void* m) {

				memcpy(this, m, sizeof(CFloat3x3));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21; float _31;
			float _12; float _22; float _32;
			float _13; float _23; float _33;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x3& m) {

				memcpy(this, &m, sizeof(CFloat3x3));

			}

		};
#pragma endregion

#pragma region CFloat3x4
		struct ING_API CFloat3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline CFloat3x4() :
				CFloat3x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline CFloat3x4(const CFloat3x4& m) {

				memcpy(this, &m, sizeof(CFloat3x4));

			}

			inline CFloat3x4(void* m) {

				memcpy(this, m, sizeof(CFloat3x4));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _12; float _13; float _14;
			float _21; float _22; float _23; float _24;
			float _31; float _32; float _33; float _34;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x4& m) {

				memcpy(this, &m, sizeof(CFloat3x4));

			}

		};
#pragma endregion

#pragma region CFloat4x2
		struct ING_API CFloat4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				m256(
					_mm256_set_ps(_42, _32, _22, _12, _41, _31, _21, _11)
				)
			{}

			inline CFloat4x2(__m256 m) : m256(m) {}
			inline CFloat4x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline CFloat4x2() :
				CFloat4x2(m256_0_0_0_0_0_0_0_0)
			{}

			inline CFloat4x2(const CFloat4x2& m) {

				memcpy(this, &m, sizeof(CFloat4x2));

			}

			inline CFloat4x2(void* m) {

				memcpy(this, m, sizeof(CFloat4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256 m256;

				struct {

					__m128 m128_1;
					__m128 m128_2;

				};

				struct {

					float _11; float _21; float _31; float _41;
					float _12; float _22; float _32; float _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4&	operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x2& m) {

				memcpy(this, &m, sizeof(CFloat4x2));

			}

		};
#pragma endregion

#pragma region CFloat4x3
		struct ING_API CFloat4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				m128_1(
					_mm_set_ps(_41, _31, _21, _11)
				),
				m128_2(
					_mm_set_ps(_42, _32, _22, _12)
				),
				m128_3(
					_mm_set_ps(_43, _33, _23, _13)
				)
			{}

			inline CFloat4x3() :
				CFloat4x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline CFloat4x3(const CFloat4x3& m) {

				memcpy(this, &m, sizeof(CFloat4x3));

			}

			inline CFloat4x3(void* m) {

				memcpy(this, m, sizeof(CFloat4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m128 m128_1;
					__m128 m128_2;
					__m128 m128_3;

				};

				struct {

					float _11; float _21; float _31; float _41; 
					float _12; float _22; float _32; float _42; 
					float _13; float _23; float _33; float _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4& operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x3& m) {

				memcpy(this, &m, sizeof(CFloat4x3));

			}

		};
#pragma endregion

#pragma region CFloat4x4
		struct ING_API CFloat4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34,
				float _41, float _42, float _43, float _44
			) :
				m256_1(
					_mm256_set_ps(_42, _32, _22, _12, _41, _31, _21, _11)
				),
				m256_2(
					_mm256_set_ps(_44, _34, _24, _14, _43, _33, _23, _13)
				)
			{}

			inline CFloat4x4(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline CFloat4x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline CFloat4x4() :
				CFloat4x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline CFloat4x4(const CFloat4x4& m) {

				memcpy(this, &m, sizeof(CFloat4x4));

			}

			inline CFloat4x4(void* m) {

				memcpy(this, m, sizeof(CFloat4x4));

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

					float _11; float _21; float _31; float _41;
					float _12; float _22; float _32; float _42;
					float _13; float _23; float _33; float _43;
					float _14; float _24; float _34; float _44;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4&	operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x4& m) {

				memcpy(this, &m, sizeof(CFloat4x4));

			}

		};
#pragma endregion
		


#pragma region RFloat2x2
		struct ING_API RFloat2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x2(
				float _11, float _12,
				float _21, float _22
			) :
				m128(
					_mm_set_ps(_22, _22, _12, _11)
				)
			{}

			inline RFloat2x2(__m128 m) : m128(m) {}

			inline RFloat2x2() :
				RFloat2x2(m128_0_0_0_0)
			{}

			inline RFloat2x2(const RFloat2x2& m) {

				memcpy(this, &m, sizeof(RFloat2x2));

			}

			inline RFloat2x2(void* m) {

				memcpy(this, m, sizeof(RFloat2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128 m128;

				struct {

					float _11; float _12;
					float _21; float _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat2x2& m) {

				memcpy(this, &m, sizeof(RFloat2x2));

			}

		};
#pragma endregion

#pragma region RFloat2x3
		struct ING_API RFloat2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline RFloat2x3() :
				RFloat2x3((void*)&m256_0_0_0_0_0_0_0_0)
			{}

			inline RFloat2x3(const RFloat2x3& m) {

				memcpy(this, &m, sizeof(RFloat2x3));

			}

			inline RFloat2x3(void* m) {

				memcpy(this, m, sizeof(RFloat2x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;float _13;
					float _21; float _22;float _23;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3&	operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat2x3& m) {

				memcpy(this, &m, sizeof(RFloat2x3));

			}

		};
#pragma endregion

#pragma region RFloat2x4
		struct ING_API RFloat2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				m256(
					_mm256_set_ps(_24, _23, _22, _21, _14, _13, _12, _11)
				)
			{}

			inline RFloat2x4(__m256 m) : m256(m) {}
			inline RFloat2x4(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RFloat2x4() :
				RFloat2x4(m256_0_0_0_0_0_0_0_0)
			{}

			inline RFloat2x4(const RFloat2x4& m) {

				memcpy(this, &m, sizeof(RFloat2x4));

			}

			inline RFloat2x4(void* m) {

				memcpy(this, m, sizeof(RFloat2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256 m256;

				struct {

					__m128 m128_1;
					__m128 m128_2;

				};

				struct {

					float _11; float _12;float _13; float _14;
					float _21; float _22;float _23; float _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
			}

			inline void		operator=(const RFloat2x4& m) {

				memcpy(this, &m, sizeof(RFloat2x4));

			}

		};
#pragma endregion

#pragma region RFloat3x2
		struct ING_API RFloat3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline RFloat3x2() :
				RFloat3x2((void*)&m256_0_0_0_0_0_0_0_0)
			{}

			inline RFloat3x2(const RFloat3x2& m) {

				memcpy(this, &m, sizeof(RFloat3x2));

			}

			inline RFloat3x2(void* m) {

				memcpy(this, m, sizeof(RFloat3x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;
					float _21; float _22;
					float _31; float _32;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat3x2& m) {

				memcpy(this, &m, sizeof(RFloat3x2));

			}

		};
#pragma endregion

#pragma region RFloat3x3
		struct ING_API RFloat3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline RFloat3x3() :
				RFloat3x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RFloat3x3(const RFloat3x3& m) {

				memcpy(this, &m, sizeof(RFloat3x3));

			}

			inline RFloat3x3(void* m) {

				memcpy(this, m, sizeof(RFloat3x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12; float _13;
					float _21; float _22; float _23;
					float _31; float _32; float _33;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3&	operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat3x3& m) {

				memcpy(this, &m, sizeof(RFloat3x3));

			}

		};
#pragma endregion

#pragma region RFloat3x4
		struct ING_API RFloat3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				m128_1(
					_mm_set_ps(_14, _13, _12, _11)
				),
				m128_2(
					_mm_set_ps(_24, _23, _22, _21)
				),
				m128_3(
					_mm_set_ps(_34, _33, _32, _31)
				)
			{}

			inline RFloat3x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3) {}

			inline RFloat3x4() :
				RFloat3x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RFloat3x4(const RFloat3x4& m) {

				memcpy(this, &m, sizeof(RFloat3x4));

			}

			inline RFloat3x4(void* m) {

				memcpy(this, m, sizeof(RFloat3x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m128 m128_1;
					__m128 m128_2;
					__m128 m128_3;

				};

				struct {

					float _11; float _12; float _13; float _14;
					float _21; float _22; float _23; float _24;
					float _31; float _32; float _33; float _34;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
			}

			inline void		operator=(const RFloat3x4& m) {

				memcpy(this, &m, sizeof(RFloat3x4));

			}

		};
#pragma endregion

#pragma region RFloat4x2
		struct ING_API RFloat4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				m256(
					_mm256_set_ps(_42, _41, _32, _31, _22, _21, _12, _11)
				)
			{}

			inline RFloat4x2(__m256 m) : m256(m) {}
			inline RFloat4x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RFloat4x2() :
				RFloat4x2(m256_0_0_0_0_0_0_0_0)
			{}

			inline RFloat4x2(const RFloat4x2& m) {

				memcpy(this, &m, sizeof(RFloat4x2));

			}

			inline RFloat4x2(void* m) {

				memcpy(this, m, sizeof(RFloat4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256 m256;

				struct {

					__m128 m128_1;
					__m128 m128_2;

				};

				struct {

					float _11; float _12;
					float _21; float _22;
					float _31; float _32;
					float _41; float _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat4x2& m) {

				memcpy(this, &m, sizeof(RFloat4x2));

			}

		};
#pragma endregion

#pragma region RFloat4x3
		struct ING_API RFloat4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33),
				_41(_41), _42(_42), _43(_43)
			{}

			inline RFloat4x3() :
				RFloat4x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RFloat4x3(const RFloat4x3& m) {

				memcpy(this, &m, sizeof(RFloat4x3));

			}

			inline RFloat4x3(void* m) {

				memcpy(this, m, sizeof(RFloat4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12; float _13;
					float _21; float _22; float _23;
					float _31; float _32; float _33;
					float _41; float _42; float _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3& operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat4x3& m) {

				memcpy(this, &m, sizeof(RFloat4x3));

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

			memcpy(((float*)result) + 3, ((float*) &f) + 4, 3 * sizeof(float));

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
#pragma endregion

#endif

	}

}



namespace ING {

	namespace Math {

#ifdef NON_SIMD

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
				CFloat2(vZeroMemoryForFloat)
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
				CFloat3(vZeroMemoryForFloat)
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

			inline CFloat4() :
				CFloat4(vZeroMemoryForFloat)
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
				RFloat2(vZeroMemoryForFloat)
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
				RFloat3(vZeroMemoryForFloat)
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
				RFloat4(vZeroMemoryForFloat)
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

		
		


#pragma region CFloat2x2
		struct ING_API CFloat2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x2(
				float _11, float _12,
				float _21, float _22
			) :
				_11(_11),
				_12(_12),
				_21(_21),
				_22(_22)
			{}

			inline CFloat2x2() :
				CFloat2x2(vZeroMemoryForFloat)
			{}

			inline CFloat2x2(const CFloat2x2& m) {

				memcpy(this, &m, sizeof(CFloat2x2));

			}

			inline CFloat2x2(void* m) {

				memcpy(this, m, sizeof(CFloat2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21;
					float _12; float _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x2& m) {

				memcpy(this, &m, sizeof(CFloat2x2));

			}

		};
#pragma endregion

#pragma region CFloat2x3
		struct ING_API CFloat2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline CFloat2x3() :
				CFloat2x3(vZeroMemoryForFloat)
			{}

			inline CFloat2x3(const CFloat2x3& m) {

				memcpy(this, &m, sizeof(CFloat2x3));

			}

			inline CFloat2x3(void* m) {

				memcpy(this, m, sizeof(CFloat2x3));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21;
			float _12; float _22; 
			float _13; float _23;



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x3& m) {

				memcpy(this, &m, sizeof(CFloat2x3));

			}

		};
#pragma endregion

#pragma region CFloat2x4
		struct ING_API CFloat2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24)
			{}

			inline CFloat2x4() :
				CFloat2x4(vZeroMemoryForFloat)
			{}

			inline CFloat2x4(const CFloat2x4& m) {

				memcpy(this, &m, sizeof(CFloat2x4));

			}

			inline CFloat2x4(void* m) {

				memcpy(this, m, sizeof(CFloat2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21;
					float _12; float _22;
					float _13; float _23;
					float _14; float _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CFloat2x4& m) {

				memcpy(this, &m, sizeof(CFloat2x4));

			}

		};
#pragma endregion

#pragma region CFloat3x2
		struct ING_API CFloat3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline CFloat3x2() :
				CFloat3x2(vZeroMemoryForFloat)
			{}

			inline CFloat3x2(const CFloat3x2& m) {

				memcpy(this, &m, sizeof(CFloat3x2));

			}

			inline CFloat3x2(void* m) {

				memcpy(this, m, sizeof(CFloat3x2));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21; float _31; 
			float _12; float _22; float _32;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x2& m) {

				memcpy(this, &m, sizeof(CFloat3x2));

			}

		};
#pragma endregion

#pragma region CFloat3x3
		struct ING_API CFloat3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline CFloat3x3() :
				CFloat3x3(vZeroMemoryForFloat)
			{}

			inline CFloat3x3(const CFloat3x3& m) {

				memcpy(this, &m, sizeof(CFloat3x3));

			}

			inline CFloat3x3(void* m) {

				memcpy(this, m, sizeof(CFloat3x3));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _21; float _31;
			float _12; float _22; float _32;
			float _13; float _23; float _33;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x3& m) {

				memcpy(this, &m, sizeof(CFloat3x3));

			}

		};
#pragma endregion

#pragma region CFloat3x4
		struct ING_API CFloat3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline CFloat3x4() :
				CFloat3x4(vZeroMemoryForFloat)
			{}

			inline CFloat3x4(const CFloat3x4& m) {

				memcpy(this, &m, sizeof(CFloat3x4));

			}

			inline CFloat3x4(void* m) {

				memcpy(this, m, sizeof(CFloat3x4));

			}



			/**
			 *	Properties
			 */
		public:
			float _11; float _12; float _13; float _14;
			float _21; float _22; float _23; float _24;
			float _31; float _32; float _33; float _34;



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CFloat3x4& m) {

				memcpy(this, &m, sizeof(CFloat3x4));

			}

		};
#pragma endregion

#pragma region CFloat4x2
		struct ING_API CFloat4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				_11(_11), _21(_21), _31(_31), _41(_41),
				_12(_12), _22(_22), _32(_32), _42(_42)
			{}

			inline CFloat4x2() :
				CFloat4x2(vZeroMemoryForFloat)
			{}

			inline CFloat4x2(const CFloat4x2& m) {

				memcpy(this, &m, sizeof(CFloat4x2));

			}

			inline CFloat4x2(void* m) {

				memcpy(this, m, sizeof(CFloat4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21; float _31; float _41;
					float _12; float _22; float _32; float _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4&	operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x2& m) {

				memcpy(this, &m, sizeof(CFloat4x2));

			}

		};
#pragma endregion

#pragma region CFloat4x3
		struct ING_API CFloat4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				_11(_11), _21(_21), _31(_31), _41(_41),
				_12(_12), _22(_22), _32(_32), _42(_42),
				_13(_13), _23(_23), _33(_33), _43(_43)
			{}

			inline CFloat4x3() :
				CFloat4x3(vZeroMemoryForFloat)
			{}

			inline CFloat4x3(const CFloat4x3& m) {

				memcpy(this, &m, sizeof(CFloat4x3));

			}

			inline CFloat4x3(void* m) {

				memcpy(this, m, sizeof(CFloat4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21; float _31; float _41; 
					float _12; float _22; float _32; float _42; 
					float _13; float _23; float _33; float _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4& operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x3& m) {

				memcpy(this, &m, sizeof(CFloat4x3));

			}

		};
#pragma endregion

#pragma region CFloat4x4
		struct ING_API CFloat4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CFloat4x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34,
				float _41, float _42, float _43, float _44
			) :
				_11(_11), _21(_21), _31(_31), _41(_41),
				_12(_12), _22(_22), _32(_32), _42(_42),
				_13(_13), _23(_23), _33(_33), _43(_43),
				_14(_14), _24(_24), _34(_34), _44(_44)
			{}

			inline CFloat4x4() :
				CFloat4x4(vZeroMemoryForFloat)
			{}

			inline CFloat4x4(const CFloat4x4& m) {

				memcpy(this, &m, sizeof(CFloat4x4));

			}

			inline CFloat4x4(void* m) {

				memcpy(this, m, sizeof(CFloat4x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21; float _31; float _41;
					float _12; float _22; float _32; float _42;
					float _13; float _23; float _33; float _43;
					float _14; float _24; float _34; float _44;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat4&	operator[](unsigned char i) {
				return *(((CFloat4*)this) + i);
			}

			inline void		operator=(const CFloat4x4& m) {

				memcpy(this, &m, sizeof(CFloat4x4));

			}

		};
#pragma endregion
		


#pragma region RFloat2x2
		struct ING_API RFloat2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x2(
				float _11, float _12,
				float _21, float _22
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22)
			{}

			inline RFloat2x2() :
				RFloat2x2(vZeroMemoryForFloat)
			{}

			inline RFloat2x2(const RFloat2x2& m) {

				memcpy(this, &m, sizeof(RFloat2x2));

			}

			inline RFloat2x2(void* m) {

				memcpy(this, m, sizeof(RFloat2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;
					float _21; float _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat2x2& m) {

				memcpy(this, &m, sizeof(RFloat2x2));

			}

		};
#pragma endregion

#pragma region RFloat2x3
		struct ING_API RFloat2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline RFloat2x3() :
				RFloat2x3(vZeroMemoryForFloat)
			{}

			inline RFloat2x3(const RFloat2x3& m) {

				memcpy(this, &m, sizeof(RFloat2x3));

			}

			inline RFloat2x3(void* m) {

				memcpy(this, m, sizeof(RFloat2x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;float _13;
					float _21; float _22;float _23;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3&	operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat2x3& m) {

				memcpy(this, &m, sizeof(RFloat2x3));

			}

		};
#pragma endregion

#pragma region RFloat2x4
		struct ING_API RFloat2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24)
			{}

			inline RFloat2x4() :
				RFloat2x4(vZeroMemoryForFloat)
			{}

			inline RFloat2x4(const RFloat2x4& m) {

				memcpy(this, &m, sizeof(RFloat2x4));

			}

			inline RFloat2x4(void* m) {

				memcpy(this, m, sizeof(RFloat2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;float _13; float _14;
					float _21; float _22;float _23; float _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
			}

			inline void		operator=(const RFloat2x4& m) {

				memcpy(this, &m, sizeof(RFloat2x4));

			}

		};
#pragma endregion

#pragma region RFloat3x2
		struct ING_API RFloat3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline RFloat3x2() :
				RFloat3x2(vZeroMemoryForFloat)
			{}

			inline RFloat3x2(const RFloat3x2& m) {

				memcpy(this, &m, sizeof(RFloat3x2));

			}

			inline RFloat3x2(void* m) {

				memcpy(this, m, sizeof(RFloat3x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;
					float _21; float _22;
					float _31; float _32;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat3x2& m) {

				memcpy(this, &m, sizeof(RFloat3x2));

			}

		};
#pragma endregion

#pragma region RFloat3x3
		struct ING_API RFloat3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline RFloat3x3() :
				RFloat3x3(vZeroMemoryForFloat)
			{}

			inline RFloat3x3(const RFloat3x3& m) {

				memcpy(this, &m, sizeof(RFloat3x3));

			}

			inline RFloat3x3(void* m) {

				memcpy(this, m, sizeof(RFloat3x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12; float _13;
					float _21; float _22; float _23;
					float _31; float _32; float _33;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3&	operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat3x3& m) {

				memcpy(this, &m, sizeof(RFloat3x3));

			}

		};
#pragma endregion

#pragma region RFloat3x4
		struct ING_API RFloat3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline RFloat3x4() :
				RFloat3x4(vZeroMemoryForFloat)
			{}

			inline RFloat3x4(const RFloat3x4& m) {

				memcpy(this, &m, sizeof(RFloat3x4));

			}

			inline RFloat3x4(void* m) {

				memcpy(this, m, sizeof(RFloat3x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12; float _13; float _14;
					float _21; float _22; float _23; float _24;
					float _31; float _32; float _33; float _34;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
			}

			inline void		operator=(const RFloat3x4& m) {

				memcpy(this, &m, sizeof(RFloat3x4));

			}

		};
#pragma endregion

#pragma region RFloat4x2
		struct ING_API RFloat4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32),
				_41(_41), _42(_42)
			{}

			inline RFloat4x2() :
				RFloat4x2(vZeroMemoryForFloat)
			{}

			inline RFloat4x2(const RFloat4x2& m) {

				memcpy(this, &m, sizeof(RFloat4x2));

			}

			inline RFloat4x2(void* m) {

				memcpy(this, m, sizeof(RFloat4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12;
					float _21; float _22;
					float _31; float _32;
					float _41; float _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RFloat4x2& m) {

				memcpy(this, &m, sizeof(RFloat4x2));

			}

		};
#pragma endregion

#pragma region RFloat4x3
		struct ING_API RFloat4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RFloat4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33),
				_41(_41), _42(_42), _43(_43)
			{}

			inline RFloat4x3() :
				RFloat4x3(vZeroMemoryForFloat)
			{}

			inline RFloat4x3(const RFloat4x3& m) {

				memcpy(this, &m, sizeof(RFloat4x3));

			}

			inline RFloat4x3(void* m) {

				memcpy(this, m, sizeof(RFloat4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _12; float _13;
					float _21; float _22; float _23;
					float _31; float _32; float _33;
					float _41; float _42; float _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3& operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RFloat4x3& m) {

				memcpy(this, &m, sizeof(RFloat4x3));

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
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34),
				_41(_41), _42(_42), _43(_43), _44(_34)
			{}

			inline RFloat4x4() :
				RFloat4x4(vZeroMemoryForFloat)
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

			memcpy(((float*)result) + 3, ((float*) &f) + 4, 3 * sizeof(float));

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
#pragma endregion

#endif

	}

}
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

#pragma region RMatrix4x4
		struct ING_API RMatrix4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix4x4(
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

			inline RMatrix4x4(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline RMatrix4x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RMatrix4x4() :
				RMatrix4x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RMatrix4x4(const RMatrix4x4& m) {

				memcpy(this, &m, sizeof(RMatrix4x4));

			}

			inline RMatrix4x4(void* m) {

				memcpy(this, m, sizeof(RMatrix4x4));

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
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

			inline void		operator=(const RMatrix4x4& m) {

				memcpy(this, &m, sizeof(RMatrix4x4));

			}

		};
		
		static inline RMatrix4x4 operator+(const RMatrix4x4& a, const RMatrix4x4& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline RMatrix4x4 operator-(const RMatrix4x4& a, const RMatrix4x4& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i RM4X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x4 operator*(const RMatrix4x4& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE))
			};
		}
		static inline RMatrix4x4 operator*(float b, const RMatrix4x4& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE))
			};
		}

		static const __m256i RM4X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x4 operator/(const RMatrix4x4& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_DIV_F_PERMUTE))
			};
		}


		static inline RMatrix4x4 operator+(const RMatrix4x4& a)					{ return a; }
		static inline RMatrix4x4 operator-(const RMatrix4x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix4x4& a, const RMatrix4x4& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(RMatrix4x4& a, const RMatrix4x4& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(RMatrix4x4& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix4x4& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X4_DIV_F_PERMUTE));
		}
#pragma endregion

	}

}
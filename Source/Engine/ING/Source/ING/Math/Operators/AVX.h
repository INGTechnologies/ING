#pragma once



/**
 *	Include Types
 */
#include "../Types/Types.h"



/**
 *	Matrix
 */
namespace ING {

	namespace Math {

#ifdef __AVX__

#pragma region CMatrix2x2		
		static inline CMatrix2x2 operator+(const CMatrix2x2& a, const CMatrix2x2& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline CMatrix2x2 operator-(const CMatrix2x2& a, const CMatrix2x2& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i CM2X2_MUL_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline CMatrix2x2 operator*(const CMatrix2x2& a, float b) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CM2X2_MUL_F_PERMUTE));
		}
		static inline CMatrix2x2 operator*(float b, const CMatrix2x2& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CM2X2_MUL_F_PERMUTE));
		}

		static const __m128i CM2X2_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline CMatrix2x2 operator/(const CMatrix2x2& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CM2X2_DIV_F_PERMUTE));
		}


		static inline CMatrix2x2 operator+(const CMatrix2x2& a)					{ return a; }
		static inline CMatrix2x2 operator-(const CMatrix2x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix2x2& a, const CMatrix2x2& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(CMatrix2x2& a, const CMatrix2x2& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(CMatrix2x2& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CM2X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix2x2& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CM2X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix2x3		
		static inline CMatrix2x3 operator+(const CMatrix2x3& a, const CMatrix2x3& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline CMatrix2x3 operator-(const CMatrix2x3& a, const CMatrix2x3& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i CM2X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix2x3 operator*(const CMatrix2x3& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X3_MUL_F_PERMUTE));
		}
		static inline CMatrix2x3 operator*(float b, const CMatrix2x3& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X3_MUL_F_PERMUTE));
		}

		static const __m256i CM2X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix2x3 operator/(const CMatrix2x3& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X3_DIV_F_PERMUTE));
		}


		static inline CMatrix2x3 operator+(const CMatrix2x3& a)					{ return a; }
		static inline CMatrix2x3 operator-(const CMatrix2x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix2x3& a, const CMatrix2x3& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(CMatrix2x3& a, const CMatrix2x3& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(CMatrix2x3& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix2x3& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix2x4
		static inline CMatrix2x4 operator+(const CMatrix2x4& a, const CMatrix2x4& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline CMatrix2x4 operator-(const CMatrix2x4& a, const CMatrix2x4& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i CM2X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix2x4 operator*(const CMatrix2x4& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X4_MUL_F_PERMUTE));
		}
		static inline CMatrix2x4 operator*(float b, const CMatrix2x4& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X4_MUL_F_PERMUTE));
		}

		static const __m256i CM2X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix2x4 operator/(const CMatrix2x4& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X4_DIV_F_PERMUTE));
		}


		static inline CMatrix2x4 operator+(const CMatrix2x4& a)					{ return a; }
		static inline CMatrix2x4 operator-(const CMatrix2x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix2x4& a, const CMatrix2x4& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(CMatrix2x4& a, const CMatrix2x4& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(CMatrix2x4& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix2x4& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM2X4_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix3x2
		static inline CMatrix3x2 operator+(const CMatrix3x2& a, const CMatrix3x2& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline CMatrix3x2 operator-(const CMatrix3x2& a, const CMatrix3x2& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i CM4X2_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x2 operator*(const CMatrix3x2& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_MUL_F_PERMUTE));
		}
		static inline CMatrix3x2 operator*(float b, const CMatrix3x2& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_MUL_F_PERMUTE));
		}

		static const __m256i CM4X2_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x2 operator/(const CMatrix3x2& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_DIV_F_PERMUTE));
		}


		static inline CMatrix3x2 operator+(const CMatrix3x2& a)					{ return a; }
		static inline CMatrix3x2 operator-(const CMatrix3x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix3x2& a, const CMatrix3x2& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(CMatrix3x2& a, const CMatrix3x2& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(CMatrix3x2& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix3x2& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix3x3
		static inline CMatrix3x3 operator+(const CMatrix3x3& a, const CMatrix3x3& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline CMatrix3x3 operator-(const CMatrix3x3& a, const CMatrix3x3& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i CM3X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x3 operator*(const CMatrix3x3& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE))
			};
		}
		static inline CMatrix3x3 operator*(float b, const CMatrix3x3& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE))
			};
		}

		static const __m256i CM3X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x3 operator/(const CMatrix3x3& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_DIV_F_PERMUTE))
			};
		}


		static inline CMatrix3x3 operator+(const CMatrix3x3& a)					{ return a; }
		static inline CMatrix3x3 operator-(const CMatrix3x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix3x3& a, const CMatrix3x3& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(CMatrix3x3& a, const CMatrix3x3& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(CMatrix3x3& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix3x3& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix3x4
		static inline CMatrix3x4 operator+(const CMatrix3x4& a, const CMatrix3x4& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline CMatrix3x4 operator-(const CMatrix3x4& a, const CMatrix3x4& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i CM3X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x4 operator*(const CMatrix3x4& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE))
			};
		}
		static inline CMatrix3x4 operator*(float b, const CMatrix3x4& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE))
			};
		}

		static const __m256i CM3X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix3x4 operator/(const CMatrix3x4& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_DIV_F_PERMUTE))
			};
		}


		static inline CMatrix3x4 operator+(const CMatrix3x4& a)					{ return a; }
		static inline CMatrix3x4 operator-(const CMatrix3x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix3x4& a, const CMatrix3x4& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(CMatrix3x4& a, const CMatrix3x4& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(CMatrix3x4& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix3x4& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X4_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix4x2
		static inline CMatrix4x2 operator+(const CMatrix4x2& a, const CMatrix4x2& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline CMatrix4x2 operator-(const CMatrix4x2& a, const CMatrix4x2& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i CM3X2_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x2 operator*(const CMatrix4x2& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X2_MUL_F_PERMUTE));
		}
		static inline CMatrix4x2 operator*(float b, const CMatrix4x2& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X2_MUL_F_PERMUTE));
		}

		static const __m256i CM3X2_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x2 operator/(const CMatrix4x2& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM3X2_DIV_F_PERMUTE));
		}


		static inline CMatrix4x2 operator+(const CMatrix4x2& a)					{ return a; }
		static inline CMatrix4x2 operator-(const CMatrix4x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix4x2& a, const CMatrix4x2& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(CMatrix4x2& a, const CMatrix4x2& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(CMatrix4x2& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix4x2& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix4x3
		static inline CMatrix4x3 operator+(const CMatrix4x3& a, const CMatrix4x3& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline CMatrix4x3 operator-(const CMatrix4x3& a, const CMatrix4x3& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i CM4X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x3 operator*(const CMatrix4x3& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE))
			};
		}
		static inline CMatrix4x3 operator*(float b, const CMatrix4x3& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE))
			};
		}

		static const __m256i CM4X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x3 operator/(const CMatrix4x3& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_DIV_F_PERMUTE))
			};
		}


		static inline CMatrix4x3 operator+(const CMatrix4x3& a)					{ return a; }
		static inline CMatrix4x3 operator-(const CMatrix4x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix4x3& a, const CMatrix4x3& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(CMatrix4x3& a, const CMatrix4x3& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(CMatrix4x3& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix4x3& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CMatrix4x4
		static inline CMatrix4x4 operator+(const CMatrix4x4& a, const CMatrix4x4& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline CMatrix4x4 operator-(const CMatrix4x4& a, const CMatrix4x4& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i CM4X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x4 operator*(const CMatrix4x4& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE))
			};
		}
		static inline CMatrix4x4 operator*(float b, const CMatrix4x4& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE))
			};
		}

		static const __m256i CM4X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline CMatrix4x4 operator/(const CMatrix4x4& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_DIV_F_PERMUTE))
			};
		}


		static inline CMatrix4x4 operator+(const CMatrix4x4& a)					{ return a; }
		static inline CMatrix4x4 operator-(const CMatrix4x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(CMatrix4x4& a, const CMatrix4x4& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(CMatrix4x4& a, const CMatrix4x4& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(CMatrix4x4& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CMatrix4x4& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), CM4X4_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix2x2
		static inline RMatrix2x2 operator+(const RMatrix2x2& a, const RMatrix2x2& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline RMatrix2x2 operator-(const RMatrix2x2& a, const RMatrix2x2& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i RM2X2_MUL_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline RMatrix2x2 operator*(const RMatrix2x2& a, float b) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RM2X2_MUL_F_PERMUTE));
		}
		static inline RMatrix2x2 operator*(float b, const RMatrix2x2& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RM2X2_MUL_F_PERMUTE));
		}

		static const __m128i RM2X2_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline RMatrix2x2 operator/(const RMatrix2x2& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RM2X2_DIV_F_PERMUTE));
		}


		static inline RMatrix2x2 operator+(const RMatrix2x2& a)					{ return a; }
		static inline RMatrix2x2 operator-(const RMatrix2x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix2x2& a, const RMatrix2x2& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(RMatrix2x2& a, const RMatrix2x2& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(RMatrix2x2& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RM2X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix2x2& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RM2X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix2x3
		static inline RMatrix2x3 operator+(const RMatrix2x3& a, const RMatrix2x3& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline RMatrix2x3 operator-(const RMatrix2x3& a, const RMatrix2x3& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i RM2X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix2x3 operator*(const RMatrix2x3& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X3_MUL_F_PERMUTE));
		}
		static inline RMatrix2x3 operator*(float b, const RMatrix2x3& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X3_MUL_F_PERMUTE));
		}

		static const __m256i RM2X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix2x3 operator/(const RMatrix2x3& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X3_DIV_F_PERMUTE));
		}


		static inline RMatrix2x3 operator+(const RMatrix2x3& a)					{ return a; }
		static inline RMatrix2x3 operator-(const RMatrix2x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix2x3& a, const RMatrix2x3& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(RMatrix2x3& a, const RMatrix2x3& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(RMatrix2x3& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix2x3& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix2x4
		static inline RMatrix2x4 operator+(const RMatrix2x4& a, const RMatrix2x4& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline RMatrix2x4 operator-(const RMatrix2x4& a, const RMatrix2x4& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i RM2X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix2x4 operator*(const RMatrix2x4& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X4_MUL_F_PERMUTE));
		}
		static inline RMatrix2x4 operator*(float b, const RMatrix2x4& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X4_MUL_F_PERMUTE));
		}

		static const __m256i RM2X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix2x4 operator/(const RMatrix2x4& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X4_DIV_F_PERMUTE));
		}


		static inline RMatrix2x4 operator+(const RMatrix2x4& a)					{ return a; }
		static inline RMatrix2x4 operator-(const RMatrix2x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix2x4& a, const RMatrix2x4& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(RMatrix2x4& a, const RMatrix2x4& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(RMatrix2x4& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix2x4& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM2X4_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix3x2
		static inline RMatrix3x2 operator+(const RMatrix3x2& a, const RMatrix3x2& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline RMatrix3x2 operator-(const RMatrix3x2& a, const RMatrix3x2& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i RM4X2_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x2 operator*(const RMatrix3x2& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_MUL_F_PERMUTE));
		}
		static inline RMatrix3x2 operator*(float b, const RMatrix3x2& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_MUL_F_PERMUTE));
		}

		static const __m256i RM4X2_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x2 operator/(const RMatrix3x2& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_DIV_F_PERMUTE));
		}


		static inline RMatrix3x2 operator+(const RMatrix3x2& a)					{ return a; }
		static inline RMatrix3x2 operator-(const RMatrix3x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix3x2& a, const RMatrix3x2& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(RMatrix3x2& a, const RMatrix3x2& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(RMatrix3x2& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix3x2& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix3x3
		static inline RMatrix3x3 operator+(const RMatrix3x3& a, const RMatrix3x3& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline RMatrix3x3 operator-(const RMatrix3x3& a, const RMatrix3x3& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i RM3X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x3 operator*(const RMatrix3x3& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE))
			};
		}
		static inline RMatrix3x3 operator*(float b, const RMatrix3x3& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE))
			};
		}

		static const __m256i RM3X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x3 operator/(const RMatrix3x3& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_DIV_F_PERMUTE))
			};
		}


		static inline RMatrix3x3 operator+(const RMatrix3x3& a)					{ return a; }
		static inline RMatrix3x3 operator-(const RMatrix3x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix3x3& a, const RMatrix3x3& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(RMatrix3x3& a, const RMatrix3x3& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(RMatrix3x3& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix3x3& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix3x4
		static inline RMatrix3x4 operator+(const RMatrix3x4& a, const RMatrix3x4& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline RMatrix3x4 operator-(const RMatrix3x4& a, const RMatrix3x4& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i RM3X4_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x4 operator*(const RMatrix3x4& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE))
			};
		}
		static inline RMatrix3x4 operator*(float b, const RMatrix3x4& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE))
			};
		}

		static const __m256i RM3X4_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix3x4 operator/(const RMatrix3x4& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_DIV_F_PERMUTE))
			};
		}


		static inline RMatrix3x4 operator+(const RMatrix3x4& a)					{ return a; }
		static inline RMatrix3x4 operator-(const RMatrix3x4& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix3x4& a, const RMatrix3x4& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(RMatrix3x4& a, const RMatrix3x4& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(RMatrix3x4& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix3x4& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X4_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix4x2
		static inline RMatrix4x2 operator+(const RMatrix4x2& a, const RMatrix4x2& b)	{ return _mm256_add_ps(a.m256, b.m256); }

		static inline RMatrix4x2 operator-(const RMatrix4x2& a, const RMatrix4x2& b)	{ return _mm256_sub_ps(a.m256, b.m256); }

		static const __m256i RM3X2_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x2 operator*(const RMatrix4x2& a, float b) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X2_MUL_F_PERMUTE));
		}
		static inline RMatrix4x2 operator*(float b, const RMatrix4x2& a) {

			return _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X2_MUL_F_PERMUTE));
		}

		static const __m256i RM3X2_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x2 operator/(const RMatrix4x2& a, float b) {

			return _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM3X2_DIV_F_PERMUTE));
		}


		static inline RMatrix4x2 operator+(const RMatrix4x2& a)					{ return a; }
		static inline RMatrix4x2 operator-(const RMatrix4x2& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix4x2& a, const RMatrix4x2& b)		{ a.m256 = _mm256_add_ps(a.m256, b.m256); }

		static inline void    operator-=(RMatrix4x2& a, const RMatrix4x2& b)		{ a.m256 = _mm256_sub_ps(a.m256, b.m256); }

		static inline void	  operator*=(RMatrix4x2& a, float b) {

			a.m256 = _mm256_mul_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix4x2& a, float b) {

			a.m256 = _mm256_div_ps(a.m256, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X2_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix4x3
		static inline RMatrix4x3 operator+(const RMatrix4x3& a, const RMatrix4x3& b)	{ return {_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2) }; }

		static inline RMatrix4x3 operator-(const RMatrix4x3& a, const RMatrix4x3& b)	{ return {_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2) }; }

		static const __m256i RM4X3_MUL_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x3 operator*(const RMatrix4x3& a, float b) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE))
			};
		}
		static inline RMatrix4x3 operator*(float b, const RMatrix4x3& a) {

			return {
				_mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE)),
				_mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE))
			};
		}

		static const __m256i RM4X3_DIV_F_PERMUTE = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);
		static inline RMatrix4x3 operator/(const RMatrix4x3& a, float b) {

			return {
				_mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_DIV_F_PERMUTE)),
				_mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_DIV_F_PERMUTE))
			};
		}


		static inline RMatrix4x3 operator+(const RMatrix4x3& a)					{ return a; }
		static inline RMatrix4x3 operator-(const RMatrix4x3& a)					{ return a * -1.0f; }



		static inline void    operator+=(RMatrix4x3& a, const RMatrix4x3& b)		{ a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }

		static inline void    operator-=(RMatrix4x3& a, const RMatrix4x3& b)		{ a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }

		static inline void	  operator*=(RMatrix4x3& a, float b) {

			a.m256_1 = _mm256_mul_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE));
			a.m256_2 = _mm256_mul_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RMatrix4x3& a, float b) {

			a.m256_1 = _mm256_div_ps(a.m256_1, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_DIV_F_PERMUTE));
			a.m256_2 = _mm256_div_ps(a.m256_2, _mm256_permutevar8x32_ps(*((__m256*) & b), RM4X3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RMatrix4x4
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

#endif

	}

}



/**
 *	Vector
 */
namespace ING {

	namespace Math {

#ifdef __AVX__

#pragma region CVector2 
		static inline CVector2 operator+(const CVector2& a, const CVector2& b) { return CVector2(a.x + b.x, a.y + b.y); }

		static inline CVector2 operator-(const CVector2& a, const CVector2& b) { return CVector2(a.x - b.x, a.y - b.y); }

		static inline CVector2 operator*(const CVector2& a, float b) { return CVector2(a.x * b, a.y * b); }
		static inline CVector2 operator*(float b, const CVector2& a) { return CVector2(a.x * b, a.y * b); }

		static inline CVector2 operator/(const CVector2& a, float b) { return CVector2(a.x / b, a.y / b); }



		static inline CVector2 operator+(const CVector2& a) { return a; }
		static inline CVector2 operator-(const CVector2& a) { return CVector2(-a.x, -a.y); }



		static inline void    operator+=(CVector2& a, const CVector2& b) { a.x += b.x; a.y += b.y; }

		static inline void    operator-=(CVector2& a, const CVector2& b) { a.x -= b.x; a.y -= b.y; }

		static inline void    operator*=(CVector2& a, float b) { a.x *= b; a.y *= b; }

		static inline void    operator/=(CVector2& a, float b) { a.x /= b; a.y /= b; }
#pragma endregion

#pragma region CVector3
		static inline CVector3 operator+(const CVector3& a, const CVector3& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline CVector3 operator-(const CVector3& a, const CVector3& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i CV3_MUL_F_PERMUTE = _mm_set_epi32(0,0,0,0);
		static inline CVector3 operator*(const CVector3& a, float b)			{ 
			
			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*)&b), CV3_MUL_F_PERMUTE));
		}
		static inline CVector3 operator*(float b, const CVector3& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_MUL_F_PERMUTE));
		}

		static const __m128i CV3_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline CVector3 operator/(const CVector3& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_DIV_F_PERMUTE));
		}



		static inline CVector3 operator+(const CVector3& a)						{ return a.m128; }
		static inline CVector3 operator-(const CVector3& a)						{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(CVector3& a, const CVector3& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(CVector3& a, const CVector3& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(CVector3& a, float b)					{ 
			
			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CVector3& a, float b)					{ 
			
			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CVector4
		static inline CVector4 operator+(const CVector4& a, const CVector4& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline CVector4 operator-(const CVector4& a, const CVector4& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i CV4_MUL_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline CVector4 operator*(const CVector4& a, float b) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_MUL_F_PERMUTE));
		}
		static inline CVector4 operator*(float b, const CVector4& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_MUL_F_PERMUTE));
		}

		static const __m128i CV4_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline CVector4 operator/(const CVector4& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_DIV_F_PERMUTE));
		}


		static inline CVector4 operator+(const CVector4& a)					{ return a.m128; }
		static inline CVector4 operator-(const CVector4& a)					{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(CVector4& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CVector4& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_DIV_F_PERMUTE));
		}
#pragma endregion



#pragma region RVector2 
		static inline RVector2 operator+(const RVector2& a, const RVector2& b) { return RVector2(a.x + b.x, a.y + b.y); }

		static inline RVector2 operator-(const RVector2& a, const RVector2& b) { return RVector2(a.x - b.x, a.y - b.y); }

		static inline RVector2 operator*(const RVector2& a, float b) { return RVector2(a.x * b, a.y * b); }
		static inline RVector2 operator*(float b, const RVector2& a) { return RVector2(a.x * b, a.y * b); }

		static inline RVector2 operator/(const RVector2& a, float b) { return RVector2(a.x / b, a.y / b); }



		static inline RVector2 operator+(const RVector2& a) { return a; }
		static inline RVector2 operator-(const RVector2& a) { return RVector2(-a.x, -a.y); }



		static inline void    operator+=(RVector2& a, const RVector2& b) { a.x += b.x; a.y += b.y; }

		static inline void    operator-=(RVector2& a, const RVector2& b) { a.x -= b.x; a.y -= b.y; }

		static inline void    operator*=(RVector2& a, float b) { a.x *= b; a.y *= b; }

		static inline void    operator/=(RVector2& a, float b) { a.x /= b; a.y /= b; }
#pragma endregion

#pragma region RVector3
		static inline RVector3 operator+(const RVector3& a, const RVector3& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline RVector3 operator-(const RVector3& a, const RVector3& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i RV3_MUL_F_PERMUTE = _mm_set_epi32(0,0,0,0);
		static inline RVector3 operator*(const RVector3& a, float b)			{ 
			
			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*)&b), RV3_MUL_F_PERMUTE));
		}
		static inline RVector3 operator*(float b, const RVector3& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_MUL_F_PERMUTE));
		}

		static const __m128i RV3_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline RVector3 operator/(const RVector3& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_DIV_F_PERMUTE));
		}



		static inline RVector3 operator+(const RVector3& a)						{ return a.m128; }
		static inline RVector3 operator-(const RVector3& a)						{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(RVector3& a, const RVector3& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(RVector3& a, const RVector3& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(RVector3& a, float b)					{ 
			
			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RVector3& a, float b)					{ 
			
			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RVector4
		static inline RVector4 operator+(const RVector4& a, const RVector4& b)	{ return _mm_add_ps(a.m128, b.m128); }

		static inline RVector4 operator-(const RVector4& a, const RVector4& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static const __m128i RV4_MUL_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline RVector4 operator*(const RVector4& a, float b) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_MUL_F_PERMUTE));
		}
		static inline RVector4 operator*(float b, const RVector4& a) {

			return _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_MUL_F_PERMUTE));
		}

		static const __m128i RV4_DIV_F_PERMUTE = _mm_set_epi32(0, 0, 0, 0);
		static inline RVector4 operator/(const RVector4& a, float b) {

			return _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_DIV_F_PERMUTE));
		}


		static inline RVector4 operator+(const RVector4& a)					{ return a.m128; }
		static inline RVector4 operator-(const RVector4& a)					{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(RVector4& a, const RVector4& b)		{ a.m128 = _mm_add_ps(a.m128, b.m128); }

		static inline void    operator-=(RVector4& a, const RVector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(RVector4& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RVector4& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_DIV_F_PERMUTE));
		}
#pragma endregion

#endif

	}

}
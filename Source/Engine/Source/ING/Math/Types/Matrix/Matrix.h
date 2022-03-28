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

#ifdef __AVX__

#pragma region RMatrix2x2
		struct ING_API RMatrix2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix2x2(
				float _11, float _12,
				float _21, float _22
			) :
				m128(
					_mm_set_ps(_22, _12, _12, _11)
				)
			{}

			inline RMatrix2x2(__m128 m) : m128(m) {}

			inline RMatrix2x2() :
				RMatrix2x2(m128_0_0_0_0)
			{}

			inline RMatrix2x2(const RMatrix2x2& m) {

				memcpy(this, &m, sizeof(RMatrix2x2));

			}

			inline RMatrix2x2(void* m) {

				memcpy(this, m, sizeof(RMatrix2x2));

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

			inline void		operator=(const RMatrix2x2& m) {

				memcpy(this, &m, sizeof(RMatrix2x2));

			}

		};
		
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
		struct ING_API RMatrix2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				m256(
					_mm256_set_ps(0, _23, _22, _21, 0, _13, _12, _11)
				)
			{}

			inline RMatrix2x3(__m256 m) : m256(m) {}
			inline RMatrix2x3(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RMatrix2x3() :
				RMatrix2x3(m256_0_0_0_0_0_0_0_0)
			{}

			inline RMatrix2x3(const RMatrix2x3& m) {

				memcpy(this, &m, sizeof(RMatrix2x3));

			}

			inline RMatrix2x3(void* m) {

				memcpy(this, m, sizeof(RMatrix2x3));

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

					float _11; float _12;float _13; float _1x;
					float _21; float _22;float _23; float _2x;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3&	operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RMatrix2x3& m) {

				memcpy(this, &m, sizeof(RMatrix2x3));

			}

		};
		
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
		struct ING_API RMatrix2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				m256(
					_mm256_set_ps(_24, _23, _22, _21, _14, _13, _12, _11)
				)
			{}

			inline RMatrix2x4(__m256 m) : m256(m) {}
			inline RMatrix2x4(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RMatrix2x4() :
				RMatrix2x4(m256_0_0_0_0_0_0_0_0)
			{}

			inline RMatrix2x4(const RMatrix2x4& m) {

				memcpy(this, &m, sizeof(RMatrix2x4));

			}

			inline RMatrix2x4(void* m) {

				memcpy(this, m, sizeof(RMatrix2x4));

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

			inline void		operator=(const RMatrix2x4& m) {

				memcpy(this, &m, sizeof(RMatrix2x4));

			}

		};
		
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
		struct ING_API RMatrix3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				m256(
					_mm256_set_ps(0, 0, _32, _31, _22, _21, _12, _11)
				)
			{}

			inline RMatrix3x2(__m256 m) : m256(m) {}
			inline RMatrix3x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RMatrix3x2() :
				RMatrix3x2(m256_0_0_0_0_0_0_0_0)
			{}

			inline RMatrix3x2(const RMatrix3x2& m) {

				memcpy(this, &m, sizeof(RMatrix3x2));

			}

			inline RMatrix3x2(void* m) {

				memcpy(this, m, sizeof(RMatrix3x2));

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

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat2&	operator[](unsigned char i) {
				return *(((RFloat2*)this) + i);
			}

			inline void		operator=(const RMatrix3x2& m) {

				memcpy(this, &m, sizeof(RMatrix3x2));

			}

		};
		
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
		struct ING_API RMatrix3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				m256_1(
					_mm256_set_ps(0, _23, _22, _21, 0, _13, _12, _11)
				),
				m256_2(
					_mm256_set_ps(0, 0, 0, 0, 0, _33, _32, _31)
				)
			{}

			inline RMatrix3x3(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline RMatrix3x3(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RMatrix3x3() :
				RMatrix3x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RMatrix3x3(const RMatrix3x3& m) {

				memcpy(this, &m, sizeof(RMatrix3x3));

			}

			inline RMatrix3x3(void* m) {

				memcpy(this, m, sizeof(RMatrix3x3));

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

					float _11; float _12; float _13; float _1x;
					float _21; float _22; float _23; float _2x;
					float _31; float _32; float _33; float _3x;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RVector3&operator[](unsigned char i) {
				return *(((RVector3*)this) + i);
			}

			inline void		operator=(const RMatrix3x3& m) {

				memcpy(this, &m, sizeof(RMatrix3x3));

			}

		};
		
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
		struct ING_API RMatrix3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				m256_1(
					_mm256_set_ps(_24, _23, _22, _21, _14, _13, _12, _11)
				),
				m256_2(
					_mm256_set_ps(0, 0, 0, 0, _34, _33, _32, _31)
				)
			{}

			inline RMatrix3x4(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline RMatrix3x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RMatrix3x4() :
				RMatrix3x4((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RMatrix3x4(const RMatrix3x4& m) {

				memcpy(this, &m, sizeof(RMatrix3x4));

			}

			inline RMatrix3x4(void* m) {

				memcpy(this, m, sizeof(RMatrix3x4));

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

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RVector4&operator[](unsigned char i) {
				return *(((RVector4*)this) + i);
			}

			inline void		operator=(const RMatrix3x4& m) {

				memcpy(this, &m, sizeof(RMatrix3x4));

			}

		};
		
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
		struct ING_API RMatrix4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				m256(
					_mm256_set_ps(_42, _41, _32, _31, _22, _21, _12, _11)
				)
			{}

			inline RMatrix4x2(__m256 m) : m256(m) {}
			inline RMatrix4x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline RMatrix4x2() :
				RMatrix4x2(m256_0_0_0_0_0_0_0_0)
			{}

			inline RMatrix4x2(const RMatrix4x2& m) {

				memcpy(this, &m, sizeof(RMatrix4x2));

			}

			inline RMatrix4x2(void* m) {

				memcpy(this, m, sizeof(RMatrix4x2));

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

			inline void		operator=(const RMatrix4x2& m) {

				memcpy(this, &m, sizeof(RMatrix4x2));

			}

		};
		
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
		struct ING_API RMatrix4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RMatrix4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				m256_1(
					_mm256_set_ps(0, _23, _22, _21, 0, _13, _12, _11)
				),
				m256_2(
					_mm256_set_ps(0, _43, _42, _41, 0, _33, _32, _31)
				)
			{}

			inline RMatrix4x3(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}
			inline RMatrix4x3(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RMatrix4x3() :
				RMatrix4x3((void*)&m256_0_0_0_0_0_0_0_0_x2)
			{}

			inline RMatrix4x3(const RMatrix4x3& m) {

				memcpy(this, &m, sizeof(RMatrix4x3));

			}

			inline RMatrix4x3(void* m) {

				memcpy(this, m, sizeof(RMatrix4x3));

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

					float _11; float _12; float _13; float _1x;
					float _21; float _22; float _23; float _2x;
					float _31; float _32; float _33; float _3x;
					float _41; float _42; float _43; float _4x;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RFloat3& operator[](unsigned char i) {
				return *(((RFloat3*)this) + i);
			}

			inline void		operator=(const RMatrix4x3& m) {

				memcpy(this, &m, sizeof(RMatrix4x3));

			}

		};
		
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
			inline RFloat4&	operator[](unsigned char i) {
				return *(((RFloat4*)this) + i);
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

#endif

	}

}
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

#pragma region CVector2 
		struct ING_API CVector2 {

			/**
			 *	Constructors
			 */
		public:
			inline CVector2(float _x, float _y) {
				x = _x;
				y = _y;
			}

			inline CVector2() :
				CVector2((void*)&m128_0_0_0_0)
			{

			}

			inline CVector2(const CVector2& m) {

				memcpy(this, &m, sizeof(CVector2));

			}

			inline CVector2(void* m) {

				memcpy(this, m, sizeof(CVector2));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;



			/**
			 *	Methods
			 */
		public:
			inline float		Length() const { return sqrt(x * x + y * y); }

			static inline float	DotProduct(CVector2 a, CVector2 b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
		
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
		struct ING_API CVector3 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CVector3(float x, float y, float z) : m128(_mm_set_ps(0,z,y,x)) {}

			inline CVector3(__m128 m) : m128(m) {}

			inline CVector3() :
				CVector3(m128_0_0_0_0)
			{

			}

			inline CVector3(const CVector3& m) : CVector3(m.m128) {}

			inline CVector3(void* m) {

				memcpy(this, m, sizeof(CVector3));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z;

				};
			};



			/**
			 *	Methods
			 */
		public:
			static inline float	DotProduct(const CVector3& v1, const CVector3& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			inline float	Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

			void			operator=(const CVector3& a) {
			
				m128 = a.m128;
			
			}

			void			operator=(__m128 m128) {

				this->m128 = m128;

			}

		};
		
		static inline CVector3 operator+(const CVector3& a, const CVector3& b)	{ return _mm_add_ps(a.m128, a.m128); }

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



		static inline void    operator+=(CVector3& a, const CVector3& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(CVector3& a, const CVector3& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(CVector3& a, float b)					{ 
			
			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CVector3& a, float b)					{ 
			
			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region CVector4
		struct ING_API CVector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CVector4(float x, float y, float z, float w) : m128(_mm_set_ps(w,z,y,x)) {}

			inline CVector4(__m128 m) : m128(m) {}

			inline CVector4() :
				CVector4(m128_0_0_0_0)
			{

			}

			inline CVector4(const CVector4& m) : CVector4(m.m128) {}

			inline CVector4(void* m) {

				memcpy(this, m, sizeof(CVector4));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z, w;

				};
			};



			/**
			 *	Methods
			 */
		public:
			static inline float	DotProduct(const CVector4& v1, const CVector4& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			inline float	Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}

			RVector4		Transpose();



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

			void			operator=(const CVector4& a) { 
			
				m128 = a.m128;
			
			}

			void			operator=(__m128 m128) {

				this->m128 = m128;

			}

		};
		
		static inline CVector4 operator+(const CVector4& a, const CVector4& b)	{ return _mm_add_ps(a.m128, a.m128); }

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



		static inline void    operator+=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(CVector4& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(CVector4& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), CV4_DIV_F_PERMUTE));
		}
#pragma endregion



#pragma region RVector2 
		struct ING_API RVector2 {

			/**
			 *	Constructors
			 */
		public:
			inline RVector2(float _x, float _y) {
				x = _x;
				y = _y;
			}

			inline RVector2() :
				RVector2((void*)&m128_0_0_0_0)
			{

			}

			inline RVector2(const RVector2& m) {

				memcpy(this, &m, sizeof(RVector2));

			}

			inline RVector2(void* m) {

				memcpy(this, m, sizeof(RVector2));

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;



			/**
			 *	Methods
			 */
		public:
			inline float		Length() const { return sqrt(x * x + y * y); }

			static inline float	DotProduct(RVector2 a, RVector2 b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
		
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
		struct ING_API RVector3 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline RVector3(float x, float y, float z) : m128(_mm_set_ps(0,z,y,x)) {}

			inline RVector3(__m128 m) : m128(m) {}

			inline RVector3() :
				RVector3(m128_0_0_0_0)
			{

			}

			inline RVector3(const RVector3& m) : RVector3(m.m128) {}

			inline RVector3(void* m) {

				memcpy(this, m, sizeof(RVector3));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z;

				};
			};



			/**
			 *	Methods
			 */
		public:
			static inline float DotProduct(const RVector3& v1, const RVector3& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			inline float	Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

			inline void		operator=(const RVector3& a) {

				m128 = a.m128;

			}

			inline void		operator=(__m128 m128) {

				this->m128 = m128;

			}

		};
		
		static inline RVector3 operator+(const RVector3& a, const RVector3& b)	{ return _mm_add_ps(a.m128, a.m128); }

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



		static inline void    operator+=(RVector3& a, const RVector3& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(RVector3& a, const RVector3& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(RVector3& a, float b)					{ 
			
			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RVector3& a, float b)					{ 
			
			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV3_DIV_F_PERMUTE));
		}
#pragma endregion

#pragma region RVector4
		struct ING_API RVector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline RVector4(float x, float y, float z, float w) : m128(_mm_set_ps(w,z,y,x)) {}

			inline RVector4(__m128 m) : m128(m) {}

			inline RVector4() :
				RVector4(m128_0_0_0_0)
			{

			}

			inline RVector4(const RVector4& m) : RVector4(m.m128) {}

			inline RVector4(void* m) {

				memcpy(this, m, sizeof(RVector4));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z, w;

				};
			};



			/**
			 *	Methods
			 */
		public:
			static inline float	DotProduct(const RVector4& v1, const RVector4& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			inline float	Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

			inline void		operator=(const RVector4& a) { 
			
				m128 = a.m128;
			
			}

			inline void		operator=(__m128 m128) {

				this->m128 = m128;

			}

		};
		
		static inline RVector4 operator+(const RVector4& a, const RVector4& b)	{ return _mm_add_ps(a.m128, a.m128); }

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



		static inline void    operator+=(RVector4& a, const RVector4& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(RVector4& a, const RVector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void	  operator*=(RVector4& a, float b) {

			a.m128 = _mm_mul_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_MUL_F_PERMUTE));
		}

		static inline void    operator/=(RVector4& a, float b) {

			a.m128 = _mm_div_ps(a.m128, _mm_permutevar_ps(*((__m128*) & b), RV4_DIV_F_PERMUTE));
		}
#pragma endregion



#pragma region VectorConvertors
		static inline CVector2& Vector(const CFloat2& f) {

			return *((CVector2*)&f);

		}
		static inline CVector3& Vector(const CFloat3& f) {

			return *((CVector3*)&f);

		}
		static inline CVector4& Vector(const CFloat4& f) {

			return *((CVector4*)&f);

		}



		static inline RVector2& Vector(const RFloat2& f) {

			return *((RVector2*)&f);

		}
		static inline RVector3& Vector(const RFloat3& f) {

			return *((RVector3*)&f);

		}
		static inline RVector4& Vector(const RFloat4& f) {

			return *((RVector4*)&f);

		}
#pragma endregion

	}

}
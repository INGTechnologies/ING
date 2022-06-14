#pragma once

/**
 *	Include Entry PointzeroMemory
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



#include "../TypeDeclares.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Math {

#ifdef __AVX__

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

			inline RVector2		Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RVector2";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
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

			inline RVector3		Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RVector3";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0B);

				std::cout << z;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

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

			inline RVector4	Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RVector4";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0B);

				std::cout << z;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0E);

				std::cout << w;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

			}



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

			inline CVector2		Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CVector2";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
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

			inline CVector3	Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CVector3";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0B);

				std::cout << z;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

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

			inline CVector4	Transpose() const;

			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CVector4";

				Debug::SetConsoleColor(0x07);

				std::cout << "(";

				Debug::SetConsoleColor(0x0C);

				std::cout << x;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0A);

				std::cout << y;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0B);

				std::cout << z;

				Debug::SetConsoleColor(0x07);

				std::cout << ", ";

				Debug::SetConsoleColor(0x0E);

				std::cout << w;

				Debug::SetConsoleColor(0x07);

				std::cout << " )";

				Debug::SetConsoleColor(0x07);

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
#pragma endregion

#endif

	}

}
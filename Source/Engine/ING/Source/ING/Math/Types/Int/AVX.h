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

#pragma region CInt2
		struct ING_API CInt2 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt2(int _x, int _y) {
				x = _x;
				y = _y;
			}

			inline CInt2() :
				CInt2((void*)&m128i_0_0_0_0)
			{

			}

			inline CInt2(const CInt2& m) {

				memcpy(this, &m, sizeof(CInt2));

			}

			inline CInt2(void* m) {

				memcpy(this, m, sizeof(CInt2));

			}



			/**
			 *	Properties
			 */
		public:
			int x;
			int y;



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CInt2";

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

		};
#pragma endregion
		
#pragma region CInt3
		struct ING_API CInt3 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt3(int _x, int _y, int _z) {
				x = _x;
				y = _y;
				z = _z;
			}

			inline CInt3() :
				CInt3((void*)&m128i_0_0_0_0)
			{

			}

			inline CInt3(const CInt3& m) {

				memcpy(this, &m, sizeof(CInt3));

			}

			inline CInt3(void* m) {

				memcpy(this, m, sizeof(CInt3));

			}



			/**
			 *	Properties
			 */
		public:
			int x;
			int y;
			int z;



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CInt3";

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

		};
#pragma endregion
		
#pragma region CInt4
		struct ING_API CInt4 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt4(int _x, int _y, int _z, int _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			inline CInt4(__m128i m) : m128(m) {}

			inline CInt4() :
				CInt4(m128i_0_0_0_0)
			{

			}

			inline CInt4(const CInt4& m) {

				memcpy(this, &m, sizeof(CInt4));

			}

			inline CInt4(void* m) {

				memcpy(this, m, sizeof(CInt4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128i m128;

				struct {

					int x;
					int y;
					int z;
					int w;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "CInt4";

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

		};
#pragma endregion



#pragma region RInt2
		struct ING_API RInt2 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt2(int _x, int _y) {
				x = _x;
				y = _y;
			}

			inline RInt2() :
				RInt2((void*)&m128i_0_0_0_0)
			{

			}

			inline RInt2(const RInt2& m) {

				memcpy(this, &m, sizeof(RInt2));

			}

			inline RInt2(void* m) {

				memcpy(this, m, sizeof(RInt2));

			}



			/**
			 *	Properties
			 */
		public:
			int x;
			int y;



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RInt2";

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

		};
#pragma endregion
		
#pragma region RInt3
		struct ING_API RInt3 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt3(int _x, int _y, int _z) {
				x = _x;
				y = _y;
				z = _z;
			}

			inline RInt3() :
				RInt3((void*)&m128i_0_0_0_0)
			{

			}

			inline RInt3(const RInt3& m) {

				memcpy(this, &m, sizeof(RInt3));

			}

			inline RInt3(void* m) {

				memcpy(this, m, sizeof(RInt3));

			}



			/**
			 *	Properties
			 */
		public:
			int x;
			int y;
			int z;



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RInt3";

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

		};
#pragma endregion
		
#pragma region RInt4
		struct ING_API RInt4 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt4(int _x, int _y, int _z, int _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			inline RInt4() :
				RInt4((void*)&m128i_0_0_0_0)
			{

			}

			inline RInt4(const RInt4& m) {

				memcpy(this, &m, sizeof(RInt4));

			}

			inline RInt4(void* m) {

				memcpy(this, m, sizeof(RInt4));

			}



			/**
			 *	Properties
			 */
		public:
			int x;
			int y;
			int z;
			int w;



			/**
			 *	Operators
			 */
		public:
			inline int& operator[](unsigned char i) {
				return *(((int*)this) + i);
			}



			/**
			 *	Methods
			 */
		public:
			void DebugLog() const {

				Debug::SetConsoleColor(0x08);

				std::cout << "RInt4";

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

		};
#pragma endregion

		
		


#pragma region CInt2x2
		struct ING_API CInt2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt2x2(
				int _11, int _12,
				int _21, int _22
			) :
				m128(
					_mm_set_epi32(_22, _12, _21, _11)
				)
			{}

			inline CInt2x2(__m128i m) : m128(m) {}

			inline CInt2x2() :
				CInt2x2(m128i_0_0_0_0)
			{}

			inline CInt2x2(const CInt2x2& m) {

				memcpy(this, &m, sizeof(CInt2x2));

			}

			inline CInt2x2(void* m) {

				memcpy(this, m, sizeof(CInt2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128i m128;

				struct {

					int _11; int _21;
					int _12; int _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CInt2&	operator[](unsigned char i) {
				return *(((CInt2*)this) + i);
			}

			inline void		operator=(const CInt2x2& m) {

				memcpy(this, &m, sizeof(CInt2x2));

			}

		};
#pragma endregion

#pragma region CInt2x3
		struct ING_API CInt2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt2x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline CInt2x3() :
				CInt2x3((void*)&m256i_0_0_0_0_0_0_0_0)
			{}

			inline CInt2x3(const CInt2x3& m) {

				memcpy(this, &m, sizeof(CInt2x3));

			}

			inline CInt2x3(void* m) {

				memcpy(this, m, sizeof(CInt2x3));

			}



			/**
			 *	Properties
			 */
		public:
			int _11; int _21;
			int _12; int _22; 
			int _13; int _23;



			/**
			 *	Operators
			 */
		public:
			inline CInt2&	operator[](unsigned char i) {
				return *(((CInt2*)this) + i);
			}

			inline void		operator=(const CInt2x3& m) {

				memcpy(this, &m, sizeof(CInt2x3));

			}

		};
#pragma endregion

#pragma region CInt2x4
		struct ING_API CInt2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt2x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24
			) :
				m256(
					_mm256_set_epi32(_24, _14, _23, _13, _22, _12, _21, _11)
				)
			{}

			inline CInt2x4(__m256i m) : m256(m) {}
			inline CInt2x4(__m128i m1, __m128i m2) : m128_1(m1), m128_2(m2) {}

			inline CInt2x4() :
				CInt2x4(m256i_0_0_0_0_0_0_0_0)
			{}

			inline CInt2x4(const CInt2x4& m) {

				memcpy(this, &m, sizeof(CInt2x4));

			}

			inline CInt2x4(void* m) {

				memcpy(this, m, sizeof(CInt2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256i m256;

				struct {

					__m128i m128_1;
					__m128i m128_2;

				};

				struct {

					int _11; int _21;
					int _12; int _22;
					int _13; int _23;
					int _14; int _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CInt2&	operator[](unsigned char i) {
				return *(((CInt2*)this) + i);
			}

			inline void		operator=(const CInt2x4& m) {

				memcpy(this, &m, sizeof(CInt2x4));

			}

		};
#pragma endregion

#pragma region CInt3x2
		struct ING_API CInt3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt3x2(
				int _11, int _12,
				int _21, int _22,
				int _31, int _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline CInt3x2() :
				CInt3x2((void*)&m256i_0_0_0_0_0_0_0_0)
			{}

			inline CInt3x2(const CInt3x2& m) {

				memcpy(this, &m, sizeof(CInt3x2));

			}

			inline CInt3x2(void* m) {

				memcpy(this, m, sizeof(CInt3x2));

			}



			/**
			 *	Properties
			 */
		public:
			int _11; int _21; int _31; 
			int _12; int _22; int _32;



			/**
			 *	Operators
			 */
		public:
			inline CInt3&	operator[](unsigned char i) {
				return *(((CInt3*)this) + i);
			}

			inline void		operator=(const CInt3x2& m) {

				memcpy(this, &m, sizeof(CInt3x2));

			}

		};
#pragma endregion

#pragma region CInt3x3
		struct ING_API CInt3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt3x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23,
				int _31, int _32, int _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline CInt3x3() :
				CInt3x3((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline CInt3x3(const CInt3x3& m) {

				memcpy(this, &m, sizeof(CInt3x3));

			}

			inline CInt3x3(void* m) {

				memcpy(this, m, sizeof(CInt3x3));

			}



			/**
			 *	Properties
			 */
		public:
			int _11; int _21; int _31;
			int _12; int _22; int _32;
			int _13; int _23; int _33;



			/**
			 *	Operators
			 */
		public:
			inline CInt3&	operator[](unsigned char i) {
				return *(((CInt3*)this) + i);
			}

			inline void		operator=(const CInt3x3& m) {

				memcpy(this, &m, sizeof(CInt3x3));

			}

		};
#pragma endregion

#pragma region CInt3x4
		struct ING_API CInt3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt3x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24,
				int _31, int _32, int _33, int _34
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline CInt3x4() :
				CInt3x4((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline CInt3x4(const CInt3x4& m) {

				memcpy(this, &m, sizeof(CInt3x4));

			}

			inline CInt3x4(void* m) {

				memcpy(this, m, sizeof(CInt3x4));

			}



			/**
			 *	Properties
			 */
		public:
			int _11; int _12; int _13; int _14;
			int _21; int _22; int _23; int _24;
			int _31; int _32; int _33; int _34;



			/**
			 *	Operators
			 */
		public:
			inline CInt3&	operator[](unsigned char i) {
				return *(((CInt3*)this) + i);
			}

			inline void		operator=(const CInt3x4& m) {

				memcpy(this, &m, sizeof(CInt3x4));

			}

		};
#pragma endregion

#pragma region CInt4x2
		struct ING_API CInt4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt4x2(
				int _11, int _12,
				int _21, int _22,
				int _31, int _32,
				int _41, int _42
			) :
				m256(
					_mm256_set_epi32(_42, _32, _22, _12, _41, _31, _21, _11)
				)
			{}

			inline CInt4x2(__m256i m) : m256(m) {}
			inline CInt4x2(__m128i m1, __m128i m2) : m128_1(m1), m128_2(m2) {}

			inline CInt4x2() :
				CInt4x2(m256i_0_0_0_0_0_0_0_0)
			{}

			inline CInt4x2(const CInt4x2& m) {

				memcpy(this, &m, sizeof(CInt4x2));

			}

			inline CInt4x2(void* m) {

				memcpy(this, m, sizeof(CInt4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256i m256;

				struct {

					__m128i m128_1;
					__m128i m128_2;

				};

				struct {

					int _11; int _21; int _31; int _41;
					int _12; int _22; int _32; int _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CInt4&	operator[](unsigned char i) {
				return *(((CInt4*)this) + i);
			}

			inline void		operator=(const CInt4x2& m) {

				memcpy(this, &m, sizeof(CInt4x2));

			}

		};
#pragma endregion

#pragma region CInt4x3
		struct ING_API CInt4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt4x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23,
				int _31, int _32, int _33,
				int _41, int _42, int _43
			) :
				m128_1(
					_mm_set_epi32(_41, _31, _21, _11)
				),
				m128_2(
					_mm_set_epi32(_42, _32, _22, _12)
				),
				m128_3(
					_mm_set_epi32(_43, _33, _23, _13)
				)
			{}

			inline CInt4x3() :
				CInt4x3((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline CInt4x3(const CInt4x3& m) {

				memcpy(this, &m, sizeof(CInt4x3));

			}

			inline CInt4x3(void* m) {

				memcpy(this, m, sizeof(CInt4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m128i m128_1;
					__m128i m128_2;
					__m128i m128_3;

				};

				struct {

					int _11; int _21; int _31; int _41; 
					int _12; int _22; int _32; int _42; 
					int _13; int _23; int _33; int _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CInt4& operator[](unsigned char i) {
				return *(((CInt4*)this) + i);
			}

			inline void		operator=(const CInt4x3& m) {

				memcpy(this, &m, sizeof(CInt4x3));

			}

		};
#pragma endregion

#pragma region CInt4x4
		struct ING_API CInt4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CInt4x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24,
				int _31, int _32, int _33, int _34,
				int _41, int _42, int _43, int _44
			) :
				m256_1(
					_mm256_set_epi32(_42, _32, _22, _12, _41, _31, _21, _11)
				),
				m256_2(
					_mm256_set_epi32(_44, _34, _24, _14, _43, _33, _23, _13)
				)
			{}

			inline CInt4x4(__m256i m1, __m256i m2) : m256_1(m1), m256_2(m2) {}
			inline CInt4x4(__m128i m1, __m128i m2, __m128i m3, __m128i m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline CInt4x4() :
				CInt4x4((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline CInt4x4(const CInt4x4& m) {

				memcpy(this, &m, sizeof(CInt4x4));

			}

			inline CInt4x4(void* m) {

				memcpy(this, m, sizeof(CInt4x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m256i m256_1;
					__m256i m256_2;

				};

				struct {

					__m128i m128_1;
					__m128i m128_2;
					__m128i m128_3;
					__m128i m128_4;

				};

				struct {

					int _11; int _21; int _31; int _41;
					int _12; int _22; int _32; int _42;
					int _13; int _23; int _33; int _43;
					int _14; int _24; int _34; int _44;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CInt4&	operator[](unsigned char i) {
				return *(((CInt4*)this) + i);
			}

			inline void		operator=(const CInt4x4& m) {

				memcpy(this, &m, sizeof(CInt4x4));

			}

		};
#pragma endregion
		


#pragma region RInt2x2
		struct ING_API RInt2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt2x2(
				int _11, int _12,
				int _21, int _22
			) :
				m128(
					_mm_set_epi32(_22, _22, _12, _11)
				)
			{}

			inline RInt2x2(__m128i m) : m128(m) {}

			inline RInt2x2() :
				RInt2x2(m128i_0_0_0_0)
			{}

			inline RInt2x2(const RInt2x2& m) {

				memcpy(this, &m, sizeof(RInt2x2));

			}

			inline RInt2x2(void* m) {

				memcpy(this, m, sizeof(RInt2x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128i m128;

				struct {

					int _11; int _12;
					int _21; int _22;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt2&	operator[](unsigned char i) {
				return *(((RInt2*)this) + i);
			}

			inline void		operator=(const RInt2x2& m) {

				memcpy(this, &m, sizeof(RInt2x2));

			}

		};
#pragma endregion

#pragma region RInt2x3
		struct ING_API RInt2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt2x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline RInt2x3() :
				RInt2x3((void*)&m256i_0_0_0_0_0_0_0_0)
			{}

			inline RInt2x3(const RInt2x3& m) {

				memcpy(this, &m, sizeof(RInt2x3));

			}

			inline RInt2x3(void* m) {

				memcpy(this, m, sizeof(RInt2x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					int _11; int _12;int _13;
					int _21; int _22;int _23;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt3&	operator[](unsigned char i) {
				return *(((RInt3*)this) + i);
			}

			inline void		operator=(const RInt2x3& m) {

				memcpy(this, &m, sizeof(RInt2x3));

			}

		};
#pragma endregion

#pragma region RInt2x4
		struct ING_API RInt2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt2x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24
			) :
				m256(
					_mm256_set_epi32(_24, _23, _22, _21, _14, _13, _12, _11)
				)
			{}

			inline RInt2x4(__m256i m) : m256(m) {}
			inline RInt2x4(__m128i m1, __m128i m2) : m128_1(m1), m128_2(m2) {}

			inline RInt2x4() :
				RInt2x4(m256i_0_0_0_0_0_0_0_0)
			{}

			inline RInt2x4(const RInt2x4& m) {

				memcpy(this, &m, sizeof(RInt2x4));

			}

			inline RInt2x4(void* m) {

				memcpy(this, m, sizeof(RInt2x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256i m256;

				struct {

					__m128i m128_1;
					__m128i m128_2;

				};

				struct {

					int _11; int _12;int _13; int _14;
					int _21; int _22;int _23; int _24;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt4&	operator[](unsigned char i) {
				return *(((RInt4*)this) + i);
			}

			inline void		operator=(const RInt2x4& m) {

				memcpy(this, &m, sizeof(RInt2x4));

			}

		};
#pragma endregion

#pragma region RInt3x2
		struct ING_API RInt3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt3x2(
				int _11, int _12,
				int _21, int _22,
				int _31, int _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline RInt3x2() :
				RInt3x2((void*)&m256i_0_0_0_0_0_0_0_0)
			{}

			inline RInt3x2(const RInt3x2& m) {

				memcpy(this, &m, sizeof(RInt3x2));

			}

			inline RInt3x2(void* m) {

				memcpy(this, m, sizeof(RInt3x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					int _11; int _12;
					int _21; int _22;
					int _31; int _32;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt2&	operator[](unsigned char i) {
				return *(((RInt2*)this) + i);
			}

			inline void		operator=(const RInt3x2& m) {

				memcpy(this, &m, sizeof(RInt3x2));

			}

		};
#pragma endregion

#pragma region RInt3x3
		struct ING_API RInt3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt3x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23,
				int _31, int _32, int _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline RInt3x3() :
				RInt3x3((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline RInt3x3(const RInt3x3& m) {

				memcpy(this, &m, sizeof(RInt3x3));

			}

			inline RInt3x3(void* m) {

				memcpy(this, m, sizeof(RInt3x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					int _11; int _12; int _13;
					int _21; int _22; int _23;
					int _31; int _32; int _33;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt3&	operator[](unsigned char i) {
				return *(((RInt3*)this) + i);
			}

			inline void		operator=(const RInt3x3& m) {

				memcpy(this, &m, sizeof(RInt3x3));

			}

		};
#pragma endregion

#pragma region RInt3x4
		struct ING_API RInt3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt3x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24,
				int _31, int _32, int _33, int _34
			) :
				m128_1(
					_mm_set_epi32(_14, _13, _12, _11)
				),
				m128_2(
					_mm_set_epi32(_24, _23, _22, _21)
				),
				m128_3(
					_mm_set_epi32(_34, _33, _32, _31)
				)
			{}

			inline RInt3x4(__m128i m1, __m128i m2, __m128i m3, __m128i m4) : m128_1(m1), m128_2(m2), m128_3(m3) {}

			inline RInt3x4() :
				RInt3x4((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline RInt3x4(const RInt3x4& m) {

				memcpy(this, &m, sizeof(RInt3x4));

			}

			inline RInt3x4(void* m) {

				memcpy(this, m, sizeof(RInt3x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m128i m128_1;
					__m128i m128_2;
					__m128i m128_3;

				};

				struct {

					int _11; int _12; int _13; int _14;
					int _21; int _22; int _23; int _24;
					int _31; int _32; int _33; int _34;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt4&	operator[](unsigned char i) {
				return *(((RInt4*)this) + i);
			}

			inline void		operator=(const RInt3x4& m) {

				memcpy(this, &m, sizeof(RInt3x4));

			}

		};
#pragma endregion

#pragma region RInt4x2
		struct ING_API RInt4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt4x2(
				int _11, int _12,
				int _21, int _22,
				int _31, int _32,
				int _41, int _42
			) :
				m256(
					_mm256_set_epi32(_42, _41, _32, _31, _22, _21, _12, _11)
				)
			{}

			inline RInt4x2(__m256i m) : m256(m) {}
			inline RInt4x2(__m128i m1, __m128i m2) : m128_1(m1), m128_2(m2) {}

			inline RInt4x2() :
				RInt4x2(m256i_0_0_0_0_0_0_0_0)
			{}

			inline RInt4x2(const RInt4x2& m) {

				memcpy(this, &m, sizeof(RInt4x2));

			}

			inline RInt4x2(void* m) {

				memcpy(this, m, sizeof(RInt4x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				__m256i m256;

				struct {

					__m128i m128_1;
					__m128i m128_2;

				};

				struct {

					int _11; int _12;
					int _21; int _22;
					int _31; int _32;
					int _41; int _42;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt2&	operator[](unsigned char i) {
				return *(((RInt2*)this) + i);
			}

			inline void		operator=(const RInt4x2& m) {

				memcpy(this, &m, sizeof(RInt4x2));

			}

		};
#pragma endregion

#pragma region RInt4x3
		struct ING_API RInt4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt4x3(
				int _11, int _12, int _13,
				int _21, int _22, int _23,
				int _31, int _32, int _33,
				int _41, int _42, int _43
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33),
				_41(_41), _42(_42), _43(_43)
			{}

			inline RInt4x3() :
				RInt4x3((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline RInt4x3(const RInt4x3& m) {

				memcpy(this, &m, sizeof(RInt4x3));

			}

			inline RInt4x3(void* m) {

				memcpy(this, m, sizeof(RInt4x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					int _11; int _12; int _13;
					int _21; int _22; int _23;
					int _31; int _32; int _33;
					int _41; int _42; int _43;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt3& operator[](unsigned char i) {
				return *(((RInt3*)this) + i);
			}

			inline void		operator=(const RInt4x3& m) {

				memcpy(this, &m, sizeof(RInt4x3));

			}

		};
#pragma endregion

#pragma region RInt4x4
		struct ING_API RInt4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline RInt4x4(
				int _11, int _12, int _13, int _14,
				int _21, int _22, int _23, int _24,
				int _31, int _32, int _33, int _34,
				int _41, int _42, int _43, int _44
			) :
				m256_1(
					_mm256_set_epi32(_24, _23, _22, _21, _14, _13, _12, _11)
				),
				m256_2(
					_mm256_set_epi32(_44, _43, _42, _41, _34, _33, _32, _31)
				)
			{}

			inline RInt4x4(__m256i m1, __m256i m2) : m256_1(m1), m256_2(m2) {}
			inline RInt4x4(__m128i m1, __m128i m2, __m128i m3, __m128i m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline RInt4x4() :
				RInt4x4((void*)&m256i_0_0_0_0_0_0_0_0_x2)
			{}

			inline RInt4x4(const RInt4x4& m) {

				memcpy(this, &m, sizeof(RInt4x4));

			}

			inline RInt4x4(void* m) {

				memcpy(this, m, sizeof(RInt4x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					__m256i m256_1;
					__m256i m256_2;

				};

				struct {

					__m128i m128_1;
					__m128i m128_2;
					__m128i m128_3;
					__m128i m128_4;

				};

				struct {

					int _11; int _12; int _13; int _14;
					int _21; int _22; int _23; int _24;
					int _31; int _32; int _33; int _34;
					int _41; int _42; int _43; int _44;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline RInt4&	operator[](unsigned char i) {
				return *(((RInt4*)this) + i);
			}

			inline void		operator=(const RInt4x4& m) {

				memcpy(this, &m, sizeof(RInt4x4));

			}

		};
#pragma endregion

#endif

	}

}
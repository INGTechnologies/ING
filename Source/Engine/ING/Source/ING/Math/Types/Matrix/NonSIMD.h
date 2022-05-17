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



#include "../Float/Float.h"
#include "../Vector/Vector.h"



namespace ING {

	namespace Math {

#ifdef NON_SIMD

		namespace {

			static const float zeroMemoryForMatrix[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
			static void* vZeroMemoryForMatrix = (float*)zeroMemoryForMatrix;

		}

#pragma region CMatrix2x2
		struct ING_API CMatrix2x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix2x2(
				float _11, float _12,
				float _21, float _22
			) :
				_11(_11),
				_12(_12),
				_21(_21),
				_22(_22)
			{}

			inline CMatrix2x2() :
				CMatrix2x2(vZeroMemoryForMatrix)
			{}

			inline CMatrix2x2(const CMatrix2x2& m) {

				memcpy(this, &m, sizeof(CMatrix2x2));

			}

			inline CMatrix2x2(void* m) {

				memcpy(this, m, sizeof(CMatrix2x2));

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

			inline void		operator=(const CMatrix2x2& m) {

				memcpy(this, &m, sizeof(CMatrix2x2));

			}

		};
#pragma endregion

#pragma region CMatrix2x3
		struct ING_API CMatrix2x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix2x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline CMatrix2x3() :
				CMatrix2x3(vZeroMemoryForMatrix)
			{}

			inline CMatrix2x3(const CMatrix2x3& m) {

				memcpy(this, &m, sizeof(CMatrix2x3));

			}

			inline CMatrix2x3(void* m) {

				memcpy(this, m, sizeof(CMatrix2x3));

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

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat2&	operator[](unsigned char i) {
				return *(((CFloat2*)this) + i);
			}

			inline void		operator=(const CMatrix2x3& m) {

				memcpy(this, &m, sizeof(CMatrix2x3));

			}

		};
#pragma endregion

#pragma region CMatrix2x4
		struct ING_API CMatrix2x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix2x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24)
			{}

			inline CMatrix2x4() :
				CMatrix2x4(vZeroMemoryForMatrix)
			{}

			inline CMatrix2x4(const CMatrix2x4& m) {

				memcpy(this, &m, sizeof(CMatrix2x4));

			}

			inline CMatrix2x4(void* m) {

				memcpy(this, m, sizeof(CMatrix2x4));

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

			inline void		operator=(const CMatrix2x4& m) {

				memcpy(this, &m, sizeof(CMatrix2x4));

			}

		};
#pragma endregion

#pragma region CMatrix3x2
		struct ING_API CMatrix3x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix3x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32
			) :
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline CMatrix3x2() :
				CMatrix3x2(vZeroMemoryForMatrix)
			{}

			inline CMatrix3x2(const CMatrix3x2& m) {

				memcpy(this, &m, sizeof(CMatrix3x2));

			}

			inline CMatrix3x2(void* m) {

				memcpy(this, m, sizeof(CMatrix3x2));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				struct {

					float _11; float _21; float _31; float _x1;
					float _12; float _22; float _32;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CFloat3&	operator[](unsigned char i) {
				return *(((CFloat3*)this) + i);
			}

			inline void		operator=(const CMatrix3x2& m) {

				memcpy(this, &m, sizeof(CMatrix3x2));

			}

		};
#pragma endregion

#pragma region CMatrix3x3
		struct ING_API CMatrix3x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix3x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33
			) :
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline CMatrix3x3() :
				CMatrix3x3(vZeroMemoryForMatrix)
			{}

			inline CMatrix3x3(const CMatrix3x3& m) {

				memcpy(this, &m, sizeof(CMatrix3x3));

			}

			inline CMatrix3x3(void* m) {

				memcpy(this, m, sizeof(CMatrix3x3));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21; float _31; float _x1;
					float _12; float _22; float _32; float _x2;
					float _13; float _23; float _33; float _x3;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CVector3&operator[](unsigned char i) {
				return *(((CVector3*)this) + i);
			}

			inline void		operator=(const CMatrix3x3& m) {

				memcpy(this, &m, sizeof(CMatrix3x3));

			}

		};
#pragma endregion

#pragma region CMatrix3x4
		struct ING_API CMatrix3x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix3x4(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34
			) :
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline CMatrix3x4() :
				CMatrix3x4(vZeroMemoryForMatrix)
			{}

			inline CMatrix3x4(const CMatrix3x4& m) {

				memcpy(this, &m, sizeof(CMatrix3x4));

			}

			inline CMatrix3x4(void* m) {

				memcpy(this, m, sizeof(CMatrix3x4));

			}



			/**
			 *	Properties
			 */
		public:
			union {

				struct {

					float _11; float _21; float _31; float _x1;
					float _12; float _22; float _32; float _x2;
					float _13; float _23; float _33; float _x3;
					float _14; float _24; float _34; float _x4;

				};

			};



			/**
			 *	Operators
			 */
		public:
			inline CVector3&operator[](unsigned char i) {
				return *(((CVector3*)this) + i);
			}

			inline void		operator=(const CMatrix3x4& m) {

				memcpy(this, &m, sizeof(CMatrix3x4));

			}

		};
#pragma endregion

#pragma region CMatrix4x2
		struct ING_API CMatrix4x2 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix4x2(
				float _11, float _12,
				float _21, float _22,
				float _31, float _32,
				float _41, float _42
			) :
				_11(_11), _21(_21), _31(_31), _41(_41),
				_12(_12), _22(_22), _32(_32), _42(_42)
			{}

			inline CMatrix4x2() :
				CMatrix4x2(vZeroMemoryForMatrix)
			{}

			inline CMatrix4x2(const CMatrix4x2& m) {

				memcpy(this, &m, sizeof(CMatrix4x2));

			}

			inline CMatrix4x2(void* m) {

				memcpy(this, m, sizeof(CMatrix4x2));

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

			inline void		operator=(const CMatrix4x2& m) {

				memcpy(this, &m, sizeof(CMatrix4x2));

			}

		};
#pragma endregion

#pragma region CMatrix4x3
		struct ING_API CMatrix4x3 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix4x3(
				float _11, float _12, float _13,
				float _21, float _22, float _23,
				float _31, float _32, float _33,
				float _41, float _42, float _43
			) :
				_11(_11), _21(_21), _31(_31), _41(_41),
				_12(_12), _22(_22), _32(_32), _42(_42),
				_13(_13), _23(_23), _33(_33), _43(_43)
			{}

			inline CMatrix4x3() :
				CMatrix4x3(vZeroMemoryForMatrix)
			{}

			inline CMatrix4x3(const CMatrix4x3& m) {

				memcpy(this, &m, sizeof(CMatrix4x3));

			}

			inline CMatrix4x3(void* m) {

				memcpy(this, m, sizeof(CMatrix4x3));

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

			inline void		operator=(const CMatrix4x3& m) {

				memcpy(this, &m, sizeof(CMatrix4x3));

			}

		};
#pragma endregion

#pragma region CMatrix4x4
		struct ING_API CMatrix4x4 {

			/**
			 *	Constructors
			 */
		public:
			inline CMatrix4x4(
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

			inline CMatrix4x4() :
				CMatrix4x4(vZeroMemoryForMatrix)
			{}

			inline CMatrix4x4(const CMatrix4x4& m) {

				memcpy(this, &m, sizeof(CMatrix4x4));

			}

			inline CMatrix4x4(void* m) {

				memcpy(this, m, sizeof(CMatrix4x4));

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

			inline void		operator=(const CMatrix4x4& m) {

				memcpy(this, &m, sizeof(CMatrix4x4));

			}

		};
#pragma endregion

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
				_11(_11), _12(_12),
				_21(_21), _22(_22)
			{}

			inline RMatrix2x2() :
				RMatrix2x2(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23)
			{}

			inline RMatrix2x3() :
				RMatrix2x3(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24)
			{}

			inline RMatrix2x4() :
				RMatrix2x4(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32)
			{}

			inline RMatrix3x2() :
				RMatrix3x2(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33)
			{}

			inline RMatrix3x3() :
				RMatrix3x3(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34)
			{}

			inline RMatrix3x4() :
				RMatrix3x4(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12),
				_21(_21), _22(_22),
				_31(_31), _32(_32),
				_41(_41), _42(_42)
			{}

			inline RMatrix4x2() :
				RMatrix4x2(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13),
				_21(_21), _22(_22), _23(_23),
				_31(_31), _32(_32), _33(_33),
				_41(_41), _42(_42), _43(_43)
			{}

			inline RMatrix4x3() :
				RMatrix4x3(vZeroMemoryForMatrix)
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
				_11(_11), _12(_12), _13(_13), _14(_14),
				_21(_21), _22(_22), _23(_23), _24(_24),
				_31(_31), _32(_32), _33(_33), _34(_34),
				_41(_41), _42(_42), _43(_43), _44(_34)
			{}

			inline RMatrix4x4() :
				RMatrix4x4(vZeroMemoryForMatrix)
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
#pragma endregion

#endif

	}

}

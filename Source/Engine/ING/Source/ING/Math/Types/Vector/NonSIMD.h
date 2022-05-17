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



namespace ING {

	namespace Math {

#ifdef NON_SIMD

		namespace {

			static const float zeroMemoryForVector[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
			static void* vZeroMemoryForVector = (float*)zeroMemoryForVector;

		}

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
				CVector2(vZeroMemoryForVector)
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
			inline CVector3(float x, float y, float z) : x(x), y(y), z(z) {}

			inline CVector3() :
				CVector3(vZeroMemoryForVector)
			{

			}

			inline CVector3(const CVector3& m) : CVector3((void*)& m) {}

			inline CVector3(void* m) {

				memcpy(this, m, sizeof(CVector3));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				struct {

					float x, y, z;

				};
			};



			/**
			 *	Methods
			 */
		public:



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
#pragma endregion

#pragma region CVector4
		struct ING_API CVector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

			inline CVector4() :
				CVector4(vZeroMemoryForVector)
			{

			}

			inline CVector4(const CVector4& m) : CVector4((void*)&m) {}

			inline CVector4(void* m) {

				memcpy(this, m, sizeof(CVector4));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				struct {

					float x, y, z, w;

				};
			};



			/**
			 *	Methods
			 */
		public:



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) {
				return *(((float*)this) + i);
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
				RVector2(vZeroMemoryForVector)
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
			inline RVector3(float x, float y, float z) : x(x), y(y), z(z) {}

			inline RVector3() :
				RVector3(vZeroMemoryForVector)
			{

			}

			inline RVector3(const RVector3& m) : RVector3((void*)&m) {}

			inline RVector3(void* m) {

				memcpy(this, m, sizeof(RVector3));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				struct {

					float x, y, z;

				};
			};



			/**
			 *	Methods
			 */
		public:



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) const {
				return *(((float*)this) + i);
			}

		};
#pragma endregion

#pragma region RVector4
		struct ING_API RVector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline RVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

			inline RVector4() :
				RVector4(vZeroMemoryForVector)
			{

			}

			inline RVector4(const RVector4& m) : RVector4((void*)&m) {}

			inline RVector4(void* m) {

				memcpy(this, m, sizeof(RVector4));

			}



			/**
			 *	Properties
			 */
		public:
			union {
				struct {

					float x, y, z, w;

				};
			};



			/**
			 *	Methods
			 */
		public:



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) {
				return *(((float*)this) + i);
			}

		};
#pragma endregion

#endif

	}

}
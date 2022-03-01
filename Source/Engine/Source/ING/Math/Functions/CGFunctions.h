#pragma once

/**
 *	Include Matrix
 */
#include <ING/Math/Matrix/Matrix.h>



/**
 *	Include Vector
 */
#include <ING/Math/Vector/Vector.h>



/**
 *	Include Quaternion
 */
#include <ING/Math/Quaternion/Quaternion.h>



/**
 *	Include Float
 */
#include <ING/Math/Float/Float.h>



namespace ING {

	namespace Math {

		static Matrix4x4	ProjectionMatrix(float fov, float aspectRatio, float nearPlane, float farPlane) {

			return Matrix4x4(
			
				Vector4(1 / (aspectRatio * ((float)tan((double)fov))), 0, 0, 0),

				Vector4(0, 1 / ((float)tan((double)fov)), 0, 0),

				Vector4(0, 0, farPlane / (farPlane - nearPlane), 1.0f),

				Vector4(0, 0, -nearPlane * farPlane / (farPlane - nearPlane), 0)
			
			);

		}

	}

}
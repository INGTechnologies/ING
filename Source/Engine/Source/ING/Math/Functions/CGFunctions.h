#pragma once

/**
 *	Include Math Types
 */
#include <ING/Math/Types/Types.h>



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
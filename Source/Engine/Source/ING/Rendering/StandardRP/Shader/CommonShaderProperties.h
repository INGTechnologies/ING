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



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



namespace ING {

	class Camera;



	namespace Rendering {

		class IDevice;



		namespace StandardRP {

#define COMMON_SHADER_PROPERTIES \
\
			ShaderProperty("ING_WorldMatrix",			sizeof(RMatrix4x4)),\
			ShaderProperty("ING_ViewMatrix",			sizeof(RMatrix4x4)),\
			ShaderProperty("ING_ProjectionMatrix",		sizeof(RMatrix4x4)),\
\
			ShaderProperty("ING_WorldViewProjMatrix",	sizeof(RMatrix4x4))\
\

		}

	}

}
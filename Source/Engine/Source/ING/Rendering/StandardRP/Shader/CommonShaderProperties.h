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



namespace ING {

	class Camera;



	namespace Rendering {

		class IDevice;



		namespace StandardRP {

#define COMMON_SHADER_PROPERTIES \
\
			ShaderProperty("ING_WorldMatrix",			sizeof(Math::Matrix4x4)),\
			ShaderProperty("ING_ViewMatrix",			sizeof(Math::Matrix4x4)),\
			ShaderProperty("ING_ProjectionMatrix",		sizeof(Math::Matrix4x4)),\
\
			ShaderProperty("ING_WorldViewProjMatrix",	sizeof(Math::Matrix4x4))\
\

		}

	}

}
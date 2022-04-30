
/**
 *	Include Header
 */
#include "SurfaceShader.h"



/**
 *	Include Scene
 */
#include <ING/Rendering/Scene/Scene.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Common Shader Properties
 */
#include <ING/Rendering/StandardRP/Shader/CommonShaderProperties.h>


#include <DirectXMath.h>

/**
 *	Include Math
 */
//#include <ING/Math/Math.h>

//using namespace ING::Math;





namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			SurfaceShader::SurfaceShader(IDevice* device, const String& name) : IShader(device, name)
			{

				

			}

			SurfaceShader::SurfaceShader(const String& name) : SurfaceShader(IAPI::GetInstance()->GetDevice(), name)
			{



			}

			SurfaceShader::~SurfaceShader()
			{



			}



			/**
			 *	Release Methods
			 */
			void SurfaceShader::Release()
			{

				IShader::Release();

			}



			/**
			 *	Methods
			 */
			void SurfaceShader::SetPropertyVector(const std::vector<ShaderProperty>& propertyVector) {

				std::vector<ShaderProperty> basePropertyVector = {

					COMMON_SHADER_PROPERTIES
				
				};

				std::vector<ShaderProperty> newPropertyVector = basePropertyVector + propertyVector;

				IShader::SetPropertyVector(newPropertyVector);

				newPropertyVector.clear();
				basePropertyVector.clear();

			}

		}

	}

}
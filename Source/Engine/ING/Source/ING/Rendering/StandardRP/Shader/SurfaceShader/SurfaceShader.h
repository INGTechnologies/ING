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



namespace ING {

	class Camera;



	namespace Rendering {

		class IDevice;



		namespace StandardRP {

			class ING_API SurfaceShader :
				public IShader
			{
				/**
				 *	Constructors And Destructor
				 */
			public:
				SurfaceShader	(IDevice* device, const std::string& name);
				SurfaceShader	(const std::string& name);
				~SurfaceShader	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void SetPropertyVector(const std::vector<ShaderProperty>& propertyVector) override;

			};

		}

	}

}
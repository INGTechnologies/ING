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

	namespace Rendering {

		class IShaderPass;

		class IDevice;



		class ING_API IPixelShader : public IShader, public AsMethod {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPixelShader	(IDevice* device);
			~IPixelShader	();



			/**
			 *	Create Methods
			 */
		public:
			static IPixelShader* CreateFromHLSL(IDevice* device, const WString& filePath);
			static IPixelShader* CreateFromHLSL(const WString& filePath);



			/**
			 *	Methods
			 */
		public:
			virtual void Apply(const String& name) override;

		};

	}

}
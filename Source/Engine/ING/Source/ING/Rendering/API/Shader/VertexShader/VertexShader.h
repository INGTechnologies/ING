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

		class C_ShaderPass;
		
		class IDevice;



		class ING_API IVertexShader : public IShader, public AsMethod {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IVertexShader	(IDevice* device);
			~IVertexShader	();



			/**
			 *	Create Methods
			 */
		public:
			static IVertexShader* CreateFromHLSL(IDevice* device, const WString& filePath);
			static IVertexShader* CreateFromHLSL(const WString& filePath);



			/**
			 *	Methods
			 */
		public:
			virtual void Apply(const String& name) override;

		};

	}

}
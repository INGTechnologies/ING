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
			static IVertexShader* CreateFromHLSL(IDevice* device, const std::wstring& filePath);
			static IVertexShader* CreateFromHLSL(const std::wstring& filePath);



			/**
			 *	Methods
			 */
		public:
			virtual void Apply(const std::string& name) override;

		};

	}

}
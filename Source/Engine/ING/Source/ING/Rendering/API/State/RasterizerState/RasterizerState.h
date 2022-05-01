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
 *	Include Rendering State
 */
#include <ING/Rendering/State/State.h>



/**
 *	Include Cullmode
 */
#include <ING/Rendering/API/CullMode/CullMode.h>



/**
 *	Include Fillmode
 */
#include <ING/Rendering/API/FillMode/FillMode.h>



namespace ING {

	namespace Rendering {

		class IShaderPass;

		class IMaterial;

		class IDevice;



		struct RasterizerStateDesc {

			FillMode	fillMode = FILL_SOLID;
			CullMode	cullMode = CULL_BACK;
			bool		frontCounterClockwise = true;
			int			depthBias = 0;
			float       depthBiasClamp = 0;
			float       slopeScaledDepthBias = 0;
			bool		depthClipEnable = true;
			bool		scissorEnable = false;
			bool		multisampleEnable = false;
			bool        antialiasedLineEnable = false;

		};



		class ING_API IRasterizerState : public IState {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IRasterizerState	(IDevice* device, const String& name, const RasterizerStateDesc& desc);
			IRasterizerState	(const String& name, const RasterizerStateDesc& desc);
			~IRasterizerState	();



			/**
			 *	Properties
			 */
		public:
			RasterizerStateDesc desc;

		public:
			const RasterizerStateDesc& GetDesc () { return desc; }



			/**
			 *	Methods
			 */
		public:
			static IRasterizerState* Create(IDevice* device, const String& name, const RasterizerStateDesc& desc);
			static IRasterizerState* Create(const String& name, const RasterizerStateDesc& desc);

			virtual void Apply() override;

		};

	}

}
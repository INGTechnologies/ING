#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



/**
 *	Include Map
 */
#include <map>



/**
 *	Include ClearFlag
 */
#include <ING/Rendering/API/ClearFlag/ClearFlag.h>



/**
 *	Include CullMode
 */
#include <ING/Rendering/API/CullMode/CullMode.h>



/**
 *	Include FillMode
 */
#include <ING/Rendering/API/FillMode/FillMode.h>



/**
 *	Include Format
 */
#include <ING/Rendering/API/Format/Format.h>



/**
 *	Include PrimitiveTopology
 */
#include <ING/Rendering/API/PrimitiveTopology/PrimitiveTopology.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	API Class
			 */
			class ING_API Convertor :
				public Rendering::Convertor
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Convertor();
				~Convertor();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release()	override;



				/**
				 *	Convert Methods
				 */
			public:
				/* Clear Flag */
				CONVERT_METHOD(clearFlagMap,			ClearFlag,				D3D11_CLEAR_FLAG);

				/* Cull Mode */
				CONVERT_METHOD(cullModeMap,				CullMode,				D3D11_CULL_MODE);

				/* FillMode */
				CONVERT_METHOD(fillModeMap,				FillMode,				D3D11_FILL_MODE);

				/* Format */
				CONVERT_METHOD(formatMap,				Format,					DXGI_FORMAT);

				/* PrimitiveTopology */
				CONVERT_METHOD(primitiveTopologyMap,	PrimitiveTopology,		D3D11_PRIMITIVE_TOPOLOGY);

			};

		}

	}

}
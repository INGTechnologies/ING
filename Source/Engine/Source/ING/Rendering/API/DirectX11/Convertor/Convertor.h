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



/**
 *	Include BindFlag
 */
#include <ING/Rendering/API/BindFlag/BindFlag.h>



/**
 *	Include CPUAccessFlag
 */
#include <ING/Rendering/API/CPUAccessFlag/CPUAccessFlag.h>



/**
 *	Include MiscFlag
 */
#include <ING/Rendering/API/MiscFlag/MiscFlag.h>



/**
 *	Include Usage
 */
#include <ING/Rendering/API/Usage/Usage.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	API Class
			 */
			class ING_API Convertor :
				public Rendering::IConvertor,
				public Singleton<Convertor>
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
				/* Clear Flag */
				CONVERTOR_METHOD(clearFlagMap,			ClearFlag,				D3D11_CLEAR_FLAG);

				/* Cull Mode */
				CONVERTOR_METHOD(cullModeMap,			CullMode,				D3D11_CULL_MODE);

				/* FillMode */
				CONVERTOR_METHOD(fillModeMap,			FillMode,				D3D11_FILL_MODE);

				/* Format */
				CONVERTOR_METHOD(formatMap,				Format,					DXGI_FORMAT);

				/* PrimitiveTopology */
				CONVERTOR_METHOD(primitiveTopologyMap,	PrimitiveTopology,		D3D11_PRIMITIVE_TOPOLOGY);

				/* BindFlag */
				CONVERTOR_METHOD(bindFlagMap,			BindFlag,				unsigned int);

				/* CPUAccessFlag */
				CONVERTOR_METHOD(cpuAccessFlagMap,		CPUAccessFlag,			D3D11_CPU_ACCESS_FLAG);

				/* MiscFlag */
				CONVERTOR_METHOD(miscFlagMap,			MiscFlag,				D3D11_RESOURCE_MISC_FLAG);

				/* Usage */
				CONVERTOR_METHOD(usageMap,				Usage,					D3D11_USAGE);

			};

		}

	}

}
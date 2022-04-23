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
 *	Include API
 */
#include <ING\Rendering/API/API.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API API : public ING::Rendering::IAPI
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				API();
				~API();



				/**
				 *	Init, Release Methods
				 */
			public:
				virtual bool Init() override;
				virtual bool Release() override;

			};

		}

	}

}
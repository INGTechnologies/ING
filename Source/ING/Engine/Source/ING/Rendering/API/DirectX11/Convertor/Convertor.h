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

			};

		}

	}

}
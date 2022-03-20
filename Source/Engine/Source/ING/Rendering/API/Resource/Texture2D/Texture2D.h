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
 *	Include Resource
 */
#include <ING/Rendering/API/Resource/Resource.h>



namespace ING {

	namespace Rendering {

		class ING_API ITexture2D : public IResource
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ITexture2D(IDevice* device);
			~ITexture2D();



			/**
			 *	Create, Release Methods
			 */
		public:
			static ITexture2D* Create(IDevice* device);

			virtual void Release() override;

		};

	}

}
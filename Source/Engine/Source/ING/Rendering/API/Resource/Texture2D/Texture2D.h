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

		class Device;



		class ING_API Texture2D : public Resource
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Texture2D(Rendering::Device* device);
			~Texture2D();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  Texture2D*	Create(Rendering::Device* device);

			virtual void		Release() override;

		};

	}

}
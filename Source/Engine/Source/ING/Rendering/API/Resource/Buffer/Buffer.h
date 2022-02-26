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



		class ING_API Buffer : public Resource
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Buffer	(Rendering::Device* device);
			~Buffer	();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  Buffer* Create(Rendering::Device* device);

			virtual void	Release() override;

		};

	}

}
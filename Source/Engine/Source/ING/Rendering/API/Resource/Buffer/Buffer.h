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

		class ING_API IBuffer : public IResource
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IBuffer	(IDevice* device);
			~IBuffer();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release() override;

		};

	}

}
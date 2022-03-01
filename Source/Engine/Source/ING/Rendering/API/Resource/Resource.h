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



namespace ING {

	namespace Rendering {

		class ING_API IResource :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IResource();
			~IResource();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
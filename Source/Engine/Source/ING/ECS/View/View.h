#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace ECS {

		class ING_API View
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			View();
			~View();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
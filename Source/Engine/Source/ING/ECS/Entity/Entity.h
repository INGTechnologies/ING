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

		struct ING_API Entity
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Entity();
			~Entity();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
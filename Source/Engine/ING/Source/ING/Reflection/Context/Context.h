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

	namespace Reflection {

		class Namespace;



		class ING_API Context
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Context		();
			~Context	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Namespace*	globalNamespace;

		public:
			Namespace*	GetNamespace	() { return globalNamespace; }

		};

	}

}
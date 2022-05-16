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

		class IClass;



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



			/**
			 *	Methods
			 */
		public:
			Namespace* CreateNamespace	(const String& fullName);

			Namespace* GetNamespace		(const String& fullName);

			IClass* GetClass			(const String& fullName);

		};

	}

}
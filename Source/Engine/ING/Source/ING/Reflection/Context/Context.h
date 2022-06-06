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

		class IStruct;



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

			IClass*		objectClass;

			IStruct*	objectStruct;

		public:
			Namespace*	GetGlobalNamespace	() { return globalNamespace; }

			IClass*		GetObjectClass	() { return objectClass; }

			IStruct*	GetObjectStruct	() { return objectStruct; }



			/**
			 *	Methods
			 */
		public:
			Namespace*	CreateNamespace	(const String& fullName);

			bool		IsHasNamespace	(const String& fullName) { return GetNamespace(fullName) != 0; }

			Namespace*	GetNamespace	(const String& fullName);

			bool		IsHasClass		(const String& fullName) { return GetClass(fullName) != 0; }

			IClass*		GetClass		(const String& fullName);

			bool		IsHasStruct		(const String& fullName) { return GetStruct(fullName) != 0; }

			IStruct*	GetStruct		(const String& fullName);

			bool		IsHasType		(const String& fullName);

		};

	}

}
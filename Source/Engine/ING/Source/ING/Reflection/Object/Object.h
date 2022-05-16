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

		class IType;

		class IClass;

		class Context;



		class ING_API IObject
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IObject		(IClass* _class);
			~IObject	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IClass*		_class;

		public:
			IClass*		GetType	() { return _class; }

		};

	}

}
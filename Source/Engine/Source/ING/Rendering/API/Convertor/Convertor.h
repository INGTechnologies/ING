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



		/**
		 *	API Class
		 */
		class ING_API Convertor :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Convertor();
			~Convertor();



			/**
			 *	Create, Release Methods
			 */
		public:
			static Convertor* Create();
			
			virtual void Release();

		};



		/**
		 * Define Macros
		 */
#define CONVERTOR_METHOD(mapName, T, TResult)\
private:\
std::map<T, TResult> mapName;\
public:\
TResult T(T key){\
		\
	return mapName[key];	\
		\
}

	}

}
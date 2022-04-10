#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Scripting {

		class ILanguage;



		class ING_API IContext
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IContext(ILanguage* language);
			~IContext();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties 
			 */
		private:
			ILanguage* language;

		public:
			ILanguage* GetLanguage() { return language; }

		};

	}

}
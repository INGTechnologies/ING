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
			IContext(const std::string& name, ILanguage* language);
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
			std::string			name;
			ILanguage*			language;

		public:
			const std::string&	GetName		() { return name; }
			ILanguage*			GetLanguage	() { return language; }

		};

	}

}
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

		class IContext;



		class ING_API ILanguage
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ILanguage();
			~ILanguage();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		protected:
			IContext* mainContext;

		public:
			IContext* GetMainContext() { return mainContext; }



			/**
			 *	Methods
			 */
		protected:
			void UpdateCreation();

		public:
			virtual std::string GetName() { return "None"; }

			virtual IContext*	CreateContext(const std::string& name);

		};

	}

}
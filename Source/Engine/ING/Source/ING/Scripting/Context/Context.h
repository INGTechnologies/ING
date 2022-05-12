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

		class IMethodContainer;

		class IOuternalMethod;



		class ING_API IContext
		{

		public:
			friend class ILanguage;



			/**
			 *	Constructors And Destructor
			 */
		public:
			IContext(const String& name, ILanguage* language);
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
			String			name;
			ILanguage*		language;

		public:
			const String&	GetName		() { return name; }
			ILanguage*		GetLanguage	() { return language; }



			/**
			 *	Methods
			 */
		public:
			virtual IOuternalMethod* GetOuternalMethod(IMethodContainer* container, const String& name);

			virtual void Load();
			virtual void Unload();
			virtual void Reload();

		};

	}

}
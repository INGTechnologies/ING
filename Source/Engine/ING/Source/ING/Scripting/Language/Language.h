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
			 *	Init, Release Method
			 */
		public:
			virtual void Init();

			virtual void Release();



			/**
			 *	Properties
			 */
		protected:
			std::unordered_map<String, IContext*>	name2ContextMap;

		public:
			IContext*	GetContext(const String& name) { 

				if (name2ContextMap.find(name) == name2ContextMap.end()) return 0;
				
				return name2ContextMap[name]; 
			}

			bool		IsHasContext(const String& name) { return !(name2ContextMap.find(name) == name2ContextMap.end()); }



			/**
			 *	Methods
			 */
		public:
			void				AddContext		(IContext* context);
			void				RemoveContext	(IContext* context);

			virtual String		GetName			() { return "None"; }

			virtual IContext*	CreateContext	(const String& name);

		};

	}

}
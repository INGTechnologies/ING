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



/**
 *	Include Language
 */
#include <ING/Scripting/Language/Language.h>



/**
 *	Include Mono
 */
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			class Context;



			class ING_API Language : public ILanguage
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Language();
				~Language();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				MonoDomain* rootDomain;

				std::unordered_map<std::string, Context*>	name2ContextMap;

			public:
				MonoDomain* GetRootDomain	() { return rootDomain; }

				Context*	GetContext		(const std::string& name) { return name2ContextMap[name]; }



				/**
				 *	Methods
				 */
			public:
				void AddContext		(Context* context);
				void RemoveContext	(Context* context);

				virtual std::string GetName()		override;

				virtual IContext*	CreateContext(const std::string& name, bool isMainContext) override;

				void OpenAssemblies(const std::string& iniFilePath, const std::string& tag);

			};

		}

	}

}
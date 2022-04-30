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

			class IAssemblyComponentCreator;



			class ING_API Language : public ILanguage
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Language();
				~Language();



				/**
				 *	Init, Release Method
				 */
			public:
				virtual void Init	() override;
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				MonoDomain* rootDomain;

				std::unordered_map<String, Context*>	name2ContextMap;

				std::unordered_map<String, IAssemblyComponentCreator*>	name2AssemblyComponentCreatorMap;

			public:
				MonoDomain* GetRootDomain	() { return rootDomain; }

				Context*	GetContext		(const String& name) { return name2ContextMap[name]; }

				IAssemblyComponentCreator* GetAssemblyComponentCreator(const String& name) { return name2AssemblyComponentCreatorMap[name]; }



				/**
				 *	Methods
				 */
			public:
				void AddContext		(Context* context);
				void RemoveContext	(Context* context);

				virtual String GetName()		override;

				virtual IContext*	CreateContext(const String& name, bool isMainContext) override;

				void OpenAssemblies(const String& iniFilePath, const String& tag);

				void AddAssemblyComponentCreator(IAssemblyComponentCreator* creator);

			};

		}

	}

}
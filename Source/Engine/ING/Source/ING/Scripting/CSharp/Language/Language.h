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

				IContext*	mainContext;

				std::unordered_map<String, IAssemblyComponentCreator*>	name2AssemblyComponentCreatorMap;

			public:
				MonoDomain* GetRootDomain	() { return rootDomain; }

				IContext*	GetMainContext() { return mainContext; }

				IAssemblyComponentCreator* GetAssemblyComponentCreator(const String& name) { return name2AssemblyComponentCreatorMap[name]; }



				/**
				 *	Methods
				 */
			public:
				virtual String GetName()		override;

				virtual IContext*	CreateContext(const String& name) override;

				void OpenAssemblies(const WString& iniFilePath, const String& tag);

				void AddAssemblyComponentCreator(IAssemblyComponentCreator* creator);

			};

		}

	}

}